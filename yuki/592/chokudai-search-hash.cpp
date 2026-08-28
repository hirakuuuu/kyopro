#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define ull unsigned long long

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

const int TIME_LIMIT = 1800;
class TimeKeeper {
private:
    chrono::high_resolution_clock::time_point start_time_;
    ll time_threshold_;
public:
    TimeKeeper(const ll &time_threshold)
        : start_time_(chrono::high_resolution_clock::now()),
          time_threshold_(time_threshold) {}
    bool isTimeOver() const {
        using chrono::duration_cast;
        using chrono::milliseconds;
        auto diff = chrono::high_resolution_clock::now() - this->start_time_;
        return duration_cast<milliseconds>(diff).count() >= time_threshold_;
    }
    double elapsed_time() const {
        using chrono::duration_cast;
        using chrono::milliseconds;
        auto diff = chrono::high_resolution_clock::now() - this->start_time_;
        return static_cast<double>(duration_cast<milliseconds>(diff).count());
    }
    double progress() const {
        using chrono::duration_cast;
        using chrono::milliseconds;
        auto diff = chrono::high_resolution_clock::now() - this->start_time_;
        return static_cast<double>(duration_cast<milliseconds>(diff).count()) / (double)time_threshold_;
    }
};

struct XorShift64 {
    ull x = 88172645463393265ull;
    inline ull next_u64(){ 
        x ^= x << 7; 
        x ^= x >> 9; 
        return x;
    }
    inline uint32_t next_u32(){
        return (uint32_t)next_u64(); 
    }
    // [lo, hi] の整数を一様にランダムに返す
    inline int next_int(int lo, int hi) {
        return lo + (int)(next_u32() % (uint32_t)(hi - lo + 1));
    }
    // [0, 1) の実数を一様にランダムに返す
    inline double next_double01() {
        ull r = next_u64();
        r = (r >> 11) | 1ULL; 
        return (double)r * (1.0 / 9007199254740992.0);
    }
};
XorShift64 rng;

int main(){
    ios::sync_with_stdio(false);    
    std::cin.tie(nullptr);

    int N, T;
    cin >> N >> T;
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, 0, N) rep(j, 0, N) cin >> A[i][j];

    const int V = N * N;
    const int NODE_LIMIT = 600000;
    const int di[4] = {-1, 1, 0, 0};
    const int dj[4] = {0, 0, -1, 1};

    auto id = [&](int i, int j) {
        return i * N + j;
    };
    auto pos = [&](int v) {
        return pair<int, int>(v / N, v % N);
    };

    vector<vector<int>> adj(V);
    rep(i, 0, N) rep(j, 0, N) {
        rep(d, 0, 4) {
            int ni = i + di[d], nj = j + dj[d];
            if(inr(0, ni, N) && inr(0, nj, N)) {
                adj[id(i, j)].push_back(id(ni, nj));
            }
        }
    }

    vector<ull> visited_hash(V), cur_hash(V);
    rep(v, 0, V) {
        visited_hash[v] = rng.next_u64();
        cur_hash[v] = rng.next_u64();
    }

    struct State {
        int cur;
        int score;
        int reachable_sum;
        int parent;
        int depth;
        ull hash;
        bitset<400> visited;
    };

    auto calc_reachable_sum = [&](const State &s, int rest) {
        if(rest <= 0) return 0;

        int sum = 0;
        array<int, 400> dist;
        dist.fill(-1);
        queue<int> que;
        dist[s.cur] = 0;
        que.push(s.cur);

        while(!que.empty()) {
            int v = que.front();
            que.pop();
            if(dist[v] == rest) continue;

            for(int nv: adj[v]) {
                if(s.visited[nv] || dist[nv] != -1) continue;
                dist[nv] = dist[v] + 1;
                sum += A[nv / N][nv % N];
                que.push(nv);
            }
        }
        return sum;
    };

    auto better = [](const State &l, const State &r) {
        if(l.score != r.score) return l.score > r.score;
        if(l.reachable_sum != r.reachable_sum) return l.reachable_sum > r.reachable_sum;
        return l.depth > r.depth;
    };

    struct CompareStateIndex {
        const vector<State> *states;
        bool operator()(int l, int r) const {
            const State &ls = (*states)[l];
            const State &rs = (*states)[r];
            if(ls.score != rs.score) return ls.score < rs.score;
            if(ls.reachable_sum != rs.reachable_sum) return ls.reachable_sum < rs.reachable_sum;
            return ls.depth < rs.depth;
        }
    };

    vector<State> states;
    states.reserve(NODE_LIMIT);
    CompareStateIndex comp{&states};
    vector<priority_queue<int, vector<int>, CompareStateIndex>> que(
        T + 1, priority_queue<int, vector<int>, CompareStateIndex>(comp)
    );
    vector<unordered_set<ull>> used(T + 1);
    rep(depth, 0, T + 1) used[depth].reserve(8192);

    rep(v, 0, V) {
        State s;
        s.cur = v;
        s.score = A[v / N][v % N];
        s.parent = -1;
        s.depth = 1;
        s.hash = visited_hash[v] ^ cur_hash[v];
        s.visited.set(v);
        s.reachable_sum = calc_reachable_sum(s, T - 1);
        states.push_back(s);
        int idx = (int)states.size() - 1;
        que[1].push(idx);
        used[1].insert(s.hash);
    }

    int best_idx = 0;
    rep(i, 1, (int)states.size()) {
        if(better(states[i], states[best_idx])) best_idx = i;
    }

    TimeKeeper time_keeper(TIME_LIMIT);
    while(!time_keeper.isTimeOver()) {
        bool updated = false;

        rrep(depth, T - 1, 1) {
            if(time_keeper.isTimeOver() || (int)states.size() >= NODE_LIMIT) break;
            if(que[depth].empty()) continue;

            int idx = que[depth].top();
            que[depth].pop();
            const State &s = states[idx];
            updated = true;

            for(int nv: adj[s.cur]) {
                if(time_keeper.isTimeOver() || (int)states.size() >= NODE_LIMIT) break;
                if(s.visited[nv]) continue;

                ull next_hash = s.hash ^ cur_hash[s.cur] ^ cur_hash[nv] ^ visited_hash[nv];
                if(used[depth + 1].find(next_hash) != used[depth + 1].end()) continue;

                State ns;
                ns.cur = nv;
                ns.score = s.score + A[nv / N][nv % N];
                ns.parent = idx;
                ns.depth = s.depth + 1;
                ns.hash = next_hash;
                ns.visited = s.visited;
                ns.visited.set(nv);
                ns.reachable_sum = calc_reachable_sum(ns, T - ns.depth);

                states.push_back(ns);
                int new_idx = (int)states.size() - 1;
                used[ns.depth].insert(ns.hash);
                que[ns.depth].push(new_idx);
                if(better(states[new_idx], states[best_idx])) {
                    best_idx = new_idx;
                }
            }
        }

        if(!updated || (int)states.size() >= NODE_LIMIT) break;
    }

    vector<int> answer;
    for(int idx = best_idx; idx != -1; idx = states[idx].parent) {
        answer.push_back(states[idx].cur);
    }
    reverse(answer.begin(), answer.end());

    int answer_score = 0;
    for(int v: answer) answer_score += A[v / N][v % N];
    cerr << "score: " << answer_score << '\n';

    cout << answer.size() << '\n';
    for(int v: answer) {
        auto [i, j] = pos(v);
        cout << i << ' ' << j << '\n';
    }
    
    return 0;
}
