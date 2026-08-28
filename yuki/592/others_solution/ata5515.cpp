#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const double TIMELIMIT = 1.98;
constexpr int TEMP_RESTART_SEGMENTS = 20;
constexpr int MOVE_WEIGHT_CORNER_FLIP = 48;
constexpr int MOVE_WEIGHT_SHORTCUT_AND_EXTEND = 24;
constexpr int MOVE_WEIGHT_DETOUR_AND_SHRINK = 20;
constexpr int MOVE_WEIGHT_ENDPOINT_SHIFT = 8;
constexpr int MOVE_WEIGHT_BACKBITE = 8;
constexpr int MOVE_WEIGHT_TOTAL =
	MOVE_WEIGHT_CORNER_FLIP +
	MOVE_WEIGHT_SHORTCUT_AND_EXTEND +
	MOVE_WEIGHT_DETOUR_AND_SHRINK +
	MOVE_WEIGHT_ENDPOINT_SHIFT +
	MOVE_WEIGHT_BACKBITE;

struct Timer {
	chrono::steady_clock::time_point start;
	Timer() { reset(); }
	void reset() { start = chrono::steady_clock::now(); }
	inline double get() const {
		return chrono::duration<double>(chrono::steady_clock::now() - start).count();
	}
};

class XorShift {
   public:
	unsigned int x, y, z, w;
	double nL[65536];

	XorShift() { init(); }

	void init() {
		x = 314159265;
		y = 358979323;
		z = 846264338;
		w = 327950288;
		double n = 1 / (double)(2 * 65536);
		for (int i = 0; i < 65536; i++) {
			nL[i] = log(((double)i / 65536) + n);
		}
	}

	inline unsigned int next() {
		unsigned int t = x ^ x << 11;
		x = y;
		y = z;
		z = w;
		return w = w ^ w >> 19 ^ t ^ t >> 8;
	}

	inline double nextLog() {
		return nL[next() & 0xFFFF];
	}

	inline int nextInt(int m) {
		return (int)(next() % m);
	}

	inline int nextInt(int min_v, int max_v) {
		return min_v + nextInt(max_v - min_v + 1);
	}

	inline double nextDouble() {
		return (double)next() / ((uint64_t)1 << 32);
	}
};

Timer timer;
XorShift rnd;

constexpr int MAX_N = 20;
constexpr int MAX_V = MAX_N * MAX_N;
constexpr int DX[4] = {1, 0, -1, 0};
constexpr int DY[4] = {0, 1, 0, -1};

int N, T;
int A[MAX_V];
int X[MAX_V];
int Y[MAX_V];
int nei[MAX_V][4];

struct Solver {
	enum MoveResult {
		INVALID = 0,
		REJECTED = 1,
		ACCEPTED_MOVE = 2,
	};

	int len = 0;
	int path[MAX_V];
	int pos[MAX_V];
	unsigned char used[MAX_V];
	int score = 0;

	int bestLen = 0;
	int bestPath[MAX_V];
	int bestScore = -1;

	int accepted = 0;
	int iterations = 0;

	static inline bool adjacent(int a, int b) {
		return (abs(X[a] - X[b]) + abs(Y[a] - Y[b])) == 1;
	}

	inline bool isFree(int v, int free1 = -1, int free2 = -1) const {
		return !used[v] || v == free1 || v == free2;
	}

	inline bool accept(int delta, double temp) {
		return delta >= 0 || delta > temp * rnd.nextLog();
	}

	inline void saveBest() {
		if (score > bestScore) {
			bestScore = score;
			bestLen = len;
			memcpy(bestPath, path, len * sizeof(int));
		}
	}

	inline void updatePosRange(int l, int r) {
		for (int i = l; i < r; i++) pos[path[i]] = i;
	}

	void readInput() {
		cin >> N >> T;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> A[i * N + j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int id = i * N + j;
				X[id] = i;
				Y[id] = j;
				for (int d = 0; d < 4; d++) {
					int ni = i + DX[d];
					int nj = j + DY[d];
					nei[id][d] = (0 <= ni && ni < N && 0 <= nj && nj < N) ? (ni * N + nj) : -1;
				}
			}
		}
	}

	void buildSnakeRow(int ord[MAX_V]) const {
		int ptr = 0;
		for (int i = 0; i < N; i++) {
			if ((i & 1) == 0) {
				for (int j = 0; j < N; j++) ord[ptr++] = i * N + j;
			} else {
				for (int j = N - 1; j >= 0; j--) ord[ptr++] = i * N + j;
			}
		}
	}

	void initPath() {
		memset(used, 0, sizeof(used));
		fill(pos, pos + MAX_V, -1);
		int ord[MAX_V];
		buildSnakeRow(ord);
		bestScore = 0;
		bestLen = T;
		for (int i = 0; i < T; i++) {
			bestPath[i] = ord[i];
			bestScore += A[ord[i]];
		}
		len = bestLen;
		score = 0;
		for (int i = 0; i < len; i++) {
			path[i] = bestPath[i];
			used[path[i]] = 1;
			pos[path[i]] = i;
			score += A[path[i]];
		}
		saveBest();
	}

	struct ExtendCand {
		int first = -1;
		int second = -1;
		int gain = -1;
		bool ok = false;
	};

	struct SplitExtendCand {
		int front = -1;
		int back = -1;
		int gain = -1;
		bool ok = false;
	};

	struct EndpointShiftCand {
		bool removeFront = false;
		int addV = -1;
		int delta = -1e9;
		bool ok = false;
	};

	ExtendCand bestExtendFront(int endpoint, int nextv, int free1, int free2) const {
		ExtendCand best;
		for (int d1 = 0; d1 < 4; d1++) {
			int near = nei[endpoint][d1];
			if (near < 0 || near == nextv || !isFree(near, free1, free2)) continue;
			for (int d2 = 0; d2 < 4; d2++) {
				int far = nei[near][d2];
				if (far < 0 || far == endpoint || !isFree(far, free1, free2)) continue;
				int gain = A[near] + A[far];
				if (!best.ok || gain > best.gain ||
				    (gain == best.gain && (int)(rnd.next() & 1))) {
					best.ok = true;
					best.first = far;
					best.second = near;
					best.gain = gain;
				}
			}
		}
		return best;
	}

	ExtendCand bestExtendBack(int endpoint, int prevv, int free1, int free2) const {
		ExtendCand best;
		for (int d1 = 0; d1 < 4; d1++) {
			int near = nei[endpoint][d1];
			if (near < 0 || near == prevv || !isFree(near, free1, free2)) continue;
			for (int d2 = 0; d2 < 4; d2++) {
				int far = nei[near][d2];
				if (far < 0 || far == endpoint || !isFree(far, free1, free2)) continue;
				int gain = A[near] + A[far];
				if (!best.ok || gain > best.gain ||
				    (gain == best.gain && (int)(rnd.next() & 1))) {
					best.ok = true;
					best.first = near;
					best.second = far;
					best.gain = gain;
				}
			}
		}
		return best;
	}

	SplitExtendCand bestExtendBothSidesOne(
		int frontEndpoint,
		int frontNext,
		int backEndpoint,
		int backPrev,
		int free1,
		int free2) const {
		SplitExtendCand best;
		for (int df = 0; df < 4; df++) {
			int fv = nei[frontEndpoint][df];
			if (fv < 0 || fv == frontNext || !isFree(fv, free1, free2)) continue;
			for (int db = 0; db < 4; db++) {
				int bv = nei[backEndpoint][db];
				if (bv < 0 || bv == backPrev || !isFree(bv, free1, free2)) continue;
				if (fv == bv) continue;
				int gain = A[fv] + A[bv];
				if (!best.ok || gain > best.gain ||
				    (gain == best.gain && (int)(rnd.next() & 1))) {
					best.ok = true;
					best.front = fv;
					best.back = bv;
					best.gain = gain;
				}
			}
		}
		return best;
	}

	MoveResult tryCornerFlip(double temp) {
		if (len < 3) return INVALID;
		int i = rnd.nextInt(len - 2);
		int a = path[i];
		int b = path[i + 1];
		int c = path[i + 2];
		if (X[a] == X[c] || Y[a] == Y[c]) return INVALID;
		int nx = X[a] + X[c] - X[b];
		int ny = Y[a] + Y[c] - Y[b];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) return INVALID;
		int nb = nx * N + ny;
		if (used[nb]) return INVALID;
		int delta = A[nb] - A[b];
		if (!accept(delta, temp)) return REJECTED;
		used[b] = 0;
		pos[b] = -1;
		used[nb] = 1;
		path[i + 1] = nb;
		pos[nb] = i + 1;
		score += delta;
		accepted++;
		saveBest();
		return ACCEPTED_MOVE;
	}

	MoveResult tryShortcutAndExtend(double temp) {
		if (len < 4) return INVALID;
		int i = rnd.nextInt(len - 3);
		int a = path[i];
		int b = path[i + 1];
		int c = path[i + 2];
		int d = path[i + 3];
		if (!adjacent(a, d)) return INVALID;

		int removed = A[b] + A[c];
		ExtendCand front, back;
		SplitExtendCand split;
		constexpr int EXTEND_FRONT_TWO = 0;
		constexpr int EXTEND_BACK_TWO = 1;
		constexpr int EXTEND_BOTH_ONE = 2;
		int mode = -1;
		if (len - 2 >= 2) {
			int f0 = (i == 0 ? a : path[0]);
			int f1 = (i == 0 ? d : path[1]);
			int e0 = (i == len - 4 ? d : path[len - 1]);
			int e1 = (i == len - 4 ? a : path[len - 2]);
			front = bestExtendFront(f0, f1, b, c);
			back = bestExtendBack(e0, e1, b, c);
			split = bestExtendBothSidesOne(f0, f1, e0, e1, b, c);
		}

		if (front.ok) mode = EXTEND_FRONT_TWO;
		if (back.ok && (mode < 0 || back.gain > front.gain ||
		                (back.gain == front.gain && (int)(rnd.next() & 1)))) {
			mode = EXTEND_BACK_TWO;
		}
		if (split.ok) {
			int baseGain = (mode == EXTEND_FRONT_TWO ? front.gain : back.gain);
			if (mode < 0 || split.gain > baseGain ||
			    (split.gain == baseGain && (int)(rnd.next() & 1))) {
				mode = EXTEND_BOTH_ONE;
			}
		}
		if (mode < 0) return INVALID;

		int extendGain = 0;
		if (mode == EXTEND_FRONT_TWO) {
			extendGain = front.gain;
		} else if (mode == EXTEND_BACK_TWO) {
			extendGain = back.gain;
		} else {
			extendGain = split.gain;
		}
		int delta = extendGain - removed;
		if (!accept(delta, temp)) return REJECTED;

		used[b] = 0;
		used[c] = 0;
		pos[b] = -1;
		pos[c] = -1;
		memmove(path + i + 1, path + i + 3, (len - (i + 3)) * sizeof(int));
		len -= 2;
		if (mode == EXTEND_FRONT_TWO) {
			memmove(path + 2, path, len * sizeof(int));
			path[0] = front.first;
			path[1] = front.second;
			used[front.first] = 1;
			used[front.second] = 1;
			updatePosRange(0, len + 2);
		} else if (mode == EXTEND_BACK_TWO) {
			path[len] = back.first;
			path[len + 1] = back.second;
			used[back.first] = 1;
			used[back.second] = 1;
			updatePosRange(i + 1, len + 2);
		} else {
			memmove(path + 1, path, len * sizeof(int));
			path[0] = split.front;
			path[len + 1] = split.back;
			used[split.front] = 1;
			used[split.back] = 1;
			updatePosRange(0, len + 2);
		}
		len += 2;
		score += delta;
		accepted++;
		saveBest();
		return ACCEPTED_MOVE;
	}

	bool detourCells(int a, int d, int side, int &b, int &c) const {
		if (X[a] == X[d]) {
			int nx = X[a] + side;
			if (nx < 0 || nx >= N) return false;
			b = nx * N + Y[a];
			c = nx * N + Y[d];
			return true;
		}
		int ny = Y[a] + side;
		if (ny < 0 || ny >= N) return false;
		b = X[a] * N + ny;
		c = X[d] * N + ny;
		return true;
	}

	MoveResult tryDetourAndShrink(double temp) {
		if (len < 3) return INVALID;
		int i = rnd.nextInt(len - 1);
		int a = path[i];
		int d = path[i + 1];

		struct Cand {
			int shrinkMode = -1;
			int b = -1;
			int c = -1;
			int delta = -1e9;
			bool ok = false;
		};

		constexpr int SHRINK_FRONT_TWO = 0;
		constexpr int SHRINK_BACK_TWO = 1;
		constexpr int SHRINK_BOTH_ONE = 2;

		Cand best;
		for (int side : {-1, 1}) {
			int b, c;
			if (!detourCells(a, d, side, b, c)) continue;
			if (used[b] || used[c]) continue;

			if (i >= 2) {
				int r0 = path[0];
				int r1 = path[1];
				int delta = A[b] + A[c] - A[r0] - A[r1];
					if (!best.ok || delta > best.delta ||
					    (delta == best.delta && (int)(rnd.next() & 1))) {
						best.ok = true;
						best.shrinkMode = SHRINK_FRONT_TWO;
						best.b = b;
						best.c = c;
						best.delta = delta;
					}
				}
				if (i + 1 <= len - 3) {
				int r0 = path[len - 2];
				int r1 = path[len - 1];
				int delta = A[b] + A[c] - A[r0] - A[r1];
					if (!best.ok || delta > best.delta ||
					    (delta == best.delta && (int)(rnd.next() & 1))) {
						best.ok = true;
						best.shrinkMode = SHRINK_BACK_TWO;
						best.b = b;
						best.c = c;
						best.delta = delta;
					}
				}
				if (i >= 1 && i <= len - 3) {
					int r0 = path[0];
					int r1 = path[len - 1];
					int delta = A[b] + A[c] - A[r0] - A[r1];
					if (!best.ok || delta > best.delta ||
					    (delta == best.delta && (int)(rnd.next() & 1))) {
						best.ok = true;
						best.shrinkMode = SHRINK_BOTH_ONE;
						best.b = b;
						best.c = c;
						best.delta = delta;
					}
				}
			}

		if (!best.ok) return INVALID;
		if (!accept(best.delta, temp)) return REJECTED;

		if (best.shrinkMode == SHRINK_FRONT_TWO) {
			int removed0 = path[0];
			int removed1 = path[1];
			used[path[0]] = 0;
			used[path[1]] = 0;
			pos[removed0] = -1;
			pos[removed1] = -1;
			memmove(path, path + 2, (len - 2) * sizeof(int));
			len -= 2;
			i -= 2;
			memmove(path + i + 3, path + i + 1, (len - (i + 1)) * sizeof(int));
			path[i + 1] = best.b;
			path[i + 2] = best.c;
			len += 2;
			used[best.b] = 1;
			used[best.c] = 1;
			updatePosRange(0, len);
		} else if (best.shrinkMode == SHRINK_BACK_TWO) {
			int removed0 = path[len - 2];
			int removed1 = path[len - 1];
			used[path[len - 1]] = 0;
			used[path[len - 2]] = 0;
			pos[removed0] = -1;
			pos[removed1] = -1;
			len -= 2;
			memmove(path + i + 3, path + i + 1, (len - (i + 1)) * sizeof(int));
			path[i + 1] = best.b;
			path[i + 2] = best.c;
			len += 2;
			used[best.b] = 1;
			used[best.c] = 1;
			updatePosRange(i + 1, len);
		} else {
			int removed0 = path[0];
			int removed1 = path[len - 1];
			used[path[0]] = 0;
			used[path[len - 1]] = 0;
			pos[removed0] = -1;
			pos[removed1] = -1;
			memmove(path, path + 1, (len - 2) * sizeof(int));
			len -= 2;
			i -= 1;
			memmove(path + i + 3, path + i + 1, (len - (i + 1)) * sizeof(int));
			path[i + 1] = best.b;
			path[i + 2] = best.c;
			len += 2;
			used[best.b] = 1;
			used[best.c] = 1;
			updatePosRange(0, len);
		}
		score += best.delta;
		accepted++;
		saveBest();
		return ACCEPTED_MOVE;
	}

	EndpointShiftCand bestEndpointShiftCand(bool removeFront) const {
		EndpointShiftCand best;
		if (len < 2) return best;

		int removed = removeFront ? path[0] : path[len - 1];
		int endpoint = removeFront ? path[len - 1] : path[0];
		int avoid = -1;
		if (len >= 3) {
			avoid = removeFront ? path[len - 2] : path[1];
		}

		for (int d = 0; d < 4; d++) {
			int nv = nei[endpoint][d];
			if (nv < 0 || nv == avoid || !isFree(nv, removed)) continue;
			int delta = A[nv] - A[removed];
			if (!best.ok || delta > best.delta ||
			    (delta == best.delta && (int)(rnd.next() & 1))) {
				best.ok = true;
				best.removeFront = removeFront;
				best.addV = nv;
				best.delta = delta;
			}
		}
		return best;
	}

	MoveResult tryEndpointShift(double temp) {
		if (len < 2) return INVALID;

		EndpointShiftCand frontCand = bestEndpointShiftCand(true);
		EndpointShiftCand backCand = bestEndpointShiftCand(false);
		if (!frontCand.ok && !backCand.ok) return INVALID;

		EndpointShiftCand best = frontCand;
		if (!best.ok || (backCand.ok && (backCand.delta > best.delta ||
		                                 (backCand.delta == best.delta &&
		                                  (int)(rnd.next() & 1))))) {
			best = backCand;
		}

		if (!accept(best.delta, temp)) return REJECTED;

		if (best.removeFront) {
			int removed = path[0];
			used[removed] = 0;
			pos[removed] = -1;
			memmove(path, path + 1, (len - 1) * sizeof(int));
			len--;
			path[len] = best.addV;
			len++;
			used[best.addV] = 1;
			updatePosRange(0, len);
		} else {
			int removed = path[len - 1];
			used[removed] = 0;
			pos[removed] = -1;
			len--;
			memmove(path + 1, path, len * sizeof(int));
			path[0] = best.addV;
			len++;
			used[best.addV] = 1;
			updatePosRange(0, len);
		}

		score += best.delta;
		accepted++;
		saveBest();
		return ACCEPTED_MOVE;
	}

	MoveResult tryBackbite() {
		if (len < 4) return INVALID;

		const bool useFront = (rnd.next() & 1);
		int candIdx[4];
		int candCount = 0;

		if (useFront) {
			int endpoint = path[0];
			int nextv = path[1];
			for (int d = 0; d < 4; d++) {
				int v = nei[endpoint][d];
				if (v < 0 || v == nextv || !used[v]) continue;
				int idx = pos[v];
				if (idx >= 2 && idx <= len - 2) {
					candIdx[candCount++] = idx;
				}
			}
			if (candCount == 0) return INVALID;
			int idx = candIdx[rnd.nextInt(candCount)];
			reverse(path, path + idx);
			updatePosRange(0, idx);
		} else {
			int endpoint = path[len - 1];
			int prevv = path[len - 2];
			for (int d = 0; d < 4; d++) {
				int v = nei[endpoint][d];
				if (v < 0 || v == prevv || !used[v]) continue;
				int idx = pos[v];
				if (idx >= 1 && idx <= len - 3) {
					candIdx[candCount++] = idx;
				}
			}
			if (candCount == 0) return INVALID;
			int idx = candIdx[rnd.nextInt(candCount)];
			reverse(path + idx + 1, path + len);
			updatePosRange(idx + 1, len);
		}

		accepted++;
		return ACCEPTED_MOVE;
	}

	void anneal() {
		const double startTemp = 1000.0;
		static_assert(TEMP_RESTART_SEGMENTS > 0, "temperature restart segments must be positive");
		static_assert(MOVE_WEIGHT_TOTAL > 0, "move weights must be positive in total");
		const double segmentDuration = TIMELIMIT / TEMP_RESTART_SEGMENTS;
		double temp = startTemp;
		int nextReport = 1;

		while (true) {
			if ((iterations & 2047) == 0) {
				double elapsed = timer.get();
				double clampedElapsed = min(elapsed, TIMELIMIT);
				int segment = min(TEMP_RESTART_SEGMENTS - 1, (int)(clampedElapsed / segmentDuration));
				double segmentStart = segment * segmentDuration;
				double localRatio = min(1.0, max(0.0, (clampedElapsed - segmentStart) / segmentDuration));
				temp = startTemp * (1.0 - localRatio) * (1.0 - localRatio);
				while (nextReport <= TEMP_RESTART_SEGMENTS &&
				       elapsed >= TIMELIMIT * nextReport / TEMP_RESTART_SEGMENTS) {
					cerr << fixed << setprecision(3)
					     << "Progress = " << nextReport << "/" << TEMP_RESTART_SEGMENTS
					     << ", Elapsed = " << elapsed
					     << ", Temperature = " << temp
					     << ", Score = " << score
					     << ", BestScore = " << bestScore
					     << ", Iter = " << iterations
					     << ", Accepted = " << accepted << '\n';
					nextReport++;
				}
				if (elapsed >= TIMELIMIT) break;
			}
			MoveResult result = INVALID;
			int r = rnd.nextInt(MOVE_WEIGHT_TOTAL);
			if (r < MOVE_WEIGHT_CORNER_FLIP) {
				result = tryCornerFlip(temp);
			} else if (r < MOVE_WEIGHT_CORNER_FLIP + MOVE_WEIGHT_SHORTCUT_AND_EXTEND) {
				result = tryShortcutAndExtend(temp);
			} else if (r < MOVE_WEIGHT_CORNER_FLIP + MOVE_WEIGHT_SHORTCUT_AND_EXTEND +
					       MOVE_WEIGHT_DETOUR_AND_SHRINK) {
				result = tryDetourAndShrink(temp);
			} else if (r < MOVE_WEIGHT_CORNER_FLIP + MOVE_WEIGHT_SHORTCUT_AND_EXTEND +
					       MOVE_WEIGHT_DETOUR_AND_SHRINK + MOVE_WEIGHT_ENDPOINT_SHIFT) {
				result = tryEndpointShift(temp);
			} else if (r < MOVE_WEIGHT_CORNER_FLIP + MOVE_WEIGHT_SHORTCUT_AND_EXTEND +
					       MOVE_WEIGHT_DETOUR_AND_SHRINK + MOVE_WEIGHT_ENDPOINT_SHIFT +
					       MOVE_WEIGHT_BACKBITE) {
				result = tryBackbite();
			}
			if (result != INVALID) iterations++;
		}

		double elapsed = timer.get();
		double clampedElapsed = min(elapsed, TIMELIMIT);
		int segment = min(TEMP_RESTART_SEGMENTS - 1, (int)(clampedElapsed / segmentDuration));
		double segmentStart = segment * segmentDuration;
		double localRatio = min(1.0, max(0.0, (clampedElapsed - segmentStart) / segmentDuration));
		temp = startTemp * (1.0 - localRatio) * (1.0 - localRatio);
		while (nextReport <= TEMP_RESTART_SEGMENTS) {
			cerr << fixed << setprecision(3)
			     << "Progress = " << nextReport << "/" << TEMP_RESTART_SEGMENTS
			     << ", Elapsed = " << elapsed
			     << ", Temperature = " << temp
			     << ", Score = " << score
			     << ", BestScore = " << bestScore
			     << ", Iter = " << iterations
			     << ", Accepted = " << accepted << '\n';
			nextReport++;
		}
	}

	void outputBest() const {
		cout << bestLen << '\n';
		for (int i = 0; i < bestLen; i++) {
			cout << X[bestPath[i]] << ' ' << Y[bestPath[i]] << '\n';
		}
	}

	void solve() {
		readInput();
		initPath();
		cerr << "InitialScore = " << score << '\n';
		anneal();
		cerr << "Iter = " << iterations << '\n';
		cerr << "Accepted = " << accepted << '\n';
		cerr << "BestScore = " << bestScore << '\n';
		outputBest();
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Solver solver;
	solver.solve();
	return 0;
}
