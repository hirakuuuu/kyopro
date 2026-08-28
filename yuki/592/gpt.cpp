#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = (a); i < (n); i++)
#define inr(l, x, r) ((l) <= (x) && (x) < (r))
using ll = long long;
using Hash = uint64_t;
using Cost = long long;

struct State {
    bitset<400> used;
    int pos = -1;
    int len = 0;
    int score = 0;
    int reachable_sum = 0;
    Hash hash = 0;
    int parent = -1;
    int action_pos = -1;

    Cost cost() const {
        // (score, reachable_sum) の辞書順最大化を，cost の最小化に変換する．
        static constexpr Cost BASE = 1000000LL;
        return -((Cost)score * BASE + (Cost)reachable_sum);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N >> T;

    vector<vector<int>> A2(N, vector<int>(N));
    rep(i, 0, N) rep(j, 0, N) cin >> A2[i][j];

    // 後で調整しやすいように，主なパラメータはここにまとめる．
    constexpr size_t BEAM_WIDTH = 1500;

    const int V = N * N;
    vector<int> A(V);

    auto id = [&](int i, int j) -> int {
        return i * N + j;
    };

    rep(i, 0, N) rep(j, 0, N) A[id(i, j)] = A2[i][j];

    mt19937_64 rng(123456789);
    vector<Hash> cell_hash(V), pos_hash(V);

    rep(i, 0, V) {
        cell_hash[i] = rng();
        pos_hash[i] = rng();
    }

    auto reachable_sum = [&](const bitset<400>& used, int start, int rem) -> int {
        if (rem <= 0) return 0;

        array<int, 400> dist;
        dist.fill(-1);

        int q[400];
        int head = 0, tail = 0;

        dist[start] = 0;
        q[tail++] = start;

        int sum = 0;

        while (head < tail) {
            int v = q[head++];
            int d = dist[v];

            if (d == rem) continue;

            int i = v / N;
            int j = v % N;

            constexpr int di[4] = {1, -1, 0, 0};
            constexpr int dj[4] = {0, 0, 1, -1};

            rep(dir, 0, 4) {
                int ni = i + di[dir];
                int nj = j + dj[dir];

                if (!inr(0, ni, N) || !inr(0, nj, N)) continue;

                int to = id(ni, nj);

                if (dist[to] != -1) continue;
                if (used[to]) continue;

                dist[to] = d + 1;
                sum += A[to];
                q[tail++] = to;
            }
        }

        return sum;
    };

    vector<State> pool;
    pool.reserve((size_t)V + (size_t)T * BEAM_WIDTH * 4 + 10);

    vector<int> curr, next;
    curr.reserve(max<size_t>(BEAM_WIDTH, V));
    next.reserve(BEAM_WIDTH * 4 + V);

    // 初期状態: 各マスに人を置く N^2 通り．
    rep(p, 0, V) {
        State st;

        st.used.set(p);
        st.pos = p;
        st.len = 1;
        st.score = A[p];
        st.reachable_sum = reachable_sum(st.used, p, T - 1);
        st.hash = cell_hash[p] ^ pos_hash[p];
        st.parent = -1;
        st.action_pos = p;

        pool.push_back(st);
        curr.push_back((int)pool.size() - 1);
    }

    auto better = [&](int lhs, int rhs) -> bool {
        Cost cl = pool[lhs].cost();
        Cost cr = pool[rhs].cost();

        if (cl != cr) return cl < cr;
        return pool[lhs].hash < pool[rhs].hash;
    };

    auto prune = [&](vector<int>& ids) {
        sort(ids.begin(), ids.end(), [&](int lhs, int rhs) {
            Cost cl = pool[lhs].cost();
            Cost cr = pool[rhs].cost();

            if (cl != cr) return cl < cr;
            return pool[lhs].hash < pool[rhs].hash;
        });

        vector<int> pruned;
        pruned.reserve(min(BEAM_WIDTH, ids.size()));

        unordered_set<Hash> seen;
        seen.reserve(min(ids.size() * 2 + 1, BEAM_WIDTH * 8 + 100));

        for (int v : ids) {
            if (seen.insert(pool[v].hash).second) {
                pruned.push_back(v);

                if (pruned.size() == BEAM_WIDTH) break;
            }
        }

        ids.swap(pruned);
    };

    prune(curr);

    int best_id = curr[0];

    for (int v : curr) {
        if (better(v, best_id)) best_id = v;
    }

    // 初期状態で len = 1 なので，次は len = 2 から作る．
    for (int turn = 1; turn < T; turn++) {
        next.clear();

        for (int idx : curr) {
            // pool.push_back による再配置で参照が壊れないよう，ここではコピーする．
            State st = pool[idx];

            int i = st.pos / N;
            int j = st.pos % N;

            constexpr int di[4] = {1, -1, 0, 0};
            constexpr int dj[4] = {0, 0, 1, -1};

            rep(dir, 0, 4) {
                int ni = i + di[dir];
                int nj = j + dj[dir];

                if (!inr(0, ni, N) || !inr(0, nj, N)) continue;

                int to = id(ni, nj);

                if (st.used[to]) continue;

                State ns = st;

                ns.used.set(to);
                ns.pos = to;
                ns.len = st.len + 1;
                ns.score = st.score + A[to];
                ns.reachable_sum = reachable_sum(ns.used, to, T - ns.len);
                ns.hash = st.hash ^ pos_hash[st.pos] ^ pos_hash[to] ^ cell_hash[to];
                ns.parent = idx;
                ns.action_pos = to;

                pool.push_back(ns);
                next.push_back((int)pool.size() - 1);
            }
        }

        if (next.empty()) break;

        prune(next);
        curr.swap(next);

        for (int v : curr) {
            if (better(v, best_id)) best_id = v;
        }
    }

    vector<int> path;

    for (int v = best_id; v != -1; v = pool[v].parent) {
        path.push_back(pool[v].action_pos);
    }

    reverse(path.begin(), path.end());

    cout << path.size() << '\n';

    for (int p : path) {
        cout << p / N << ' ' << p % N << '\n';
    }

    return 0;
}