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

const int TIME_LIMIT = 1900;
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

template <typename T, int MAX_SIZE>
class StaticPriorityQueue {
private:
    T data[MAX_SIZE];
    int sz;
public:
    StaticPriorityQueue() : sz(0) {}
    inline void clear() { sz = 0; }
    inline bool empty() const { return sz == 0; }
    inline int size() const { return sz; }
    inline void push(const T& val) {
        data[sz] = val;
        std::push_heap(data, data + sz + 1);
        sz++;
    }
    inline const T& top() const { return data[0]; }
    inline void pop() {
        std::pop_heap(data, data + sz);
        sz--;
    }
};

struct State {
    int cur;
    int score;
    int reachable_sum;
    int reachable_count;
    int parent;
    int depth;
    bitset<400> visited;
};

constexpr ll EVAL_SCORE_WEIGHT = 30000;
constexpr ll EVAL_REACHABLE_SUM_WEIGHT = 50;
constexpr ll EVAL_REACHABLE_COUNT_WEIGHT = 100;
constexpr ll EVAL_DEPTH_WEIGHT = 10;

inline ll eval_state(const State &s) {
    return (ll)s.score * EVAL_SCORE_WEIGHT
         + (ll)s.reachable_sum * EVAL_REACHABLE_SUM_WEIGHT
         + (ll)s.reachable_count * EVAL_REACHABLE_COUNT_WEIGHT
         + (ll)s.depth * EVAL_DEPTH_WEIGHT;
}

struct QueueItem {
    int idx;
    static const vector<State> *states;

    bool operator<(const QueueItem &other) const {
        ll l_eval = eval_state((*states)[idx]);
        ll r_eval = eval_state((*states)[other.idx]);
        if(l_eval != r_eval) return l_eval < r_eval;
        return idx < other.idx;
    }
};
const vector<State> *QueueItem::states = nullptr;

int main(){
    ios::sync_with_stdio(false);    
    std::cin.tie(nullptr);

    int N, T;
    cin >> N >> T;
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, 0, N) rep(j, 0, N) cin >> A[i][j];

    const int V = N * N;
    const int NODE_LIMIT = 3000000;
    const int QUEUE_KEEP_LIMIT = 10000;
    const int QUEUE_MAX_SIZE = 20000;
    const int di[4] = {-1, 1, 0, 0};
    const int dj[4] = {0, 0, -1, 1};

    auto id = [&](int i, int j) {
        return i * N + j;
    };
    auto pos = [&](int v) {
        return pair<int, int>(v / N, v % N);
    };

    array<int, 400> value{};
    rep(i, 0, N) rep(j, 0, N) value[id(i, j)] = A[i][j];

    auto calc_path_score = [&](const vector<int> &path) {
        int score = 0;
        for(int v: path) score += value[v];
        return score;
    };

    vector<int> zigzag_path;
    zigzag_path.reserve(T);
    rep(i, 0, N) {
        if(i % 2 == 0) {
            rep(j, 0, N) {
                if((int)zigzag_path.size() == T) break;
                zigzag_path.push_back(id(i, j));
            }
        }else{
            rrep(j, N - 1, 0) {
                if((int)zigzag_path.size() == T) break;
                zigzag_path.push_back(id(i, j));
            }
        }
        if((int)zigzag_path.size() == T) break;
    }
    int zigzag_score = calc_path_score(zigzag_path);

    array<array<int, 4>, 400> adj;
    array<int, 400> deg{};
    rep(i, 0, N) rep(j, 0, N) {
        int v = id(i, j);
        rep(d, 0, 4) {
            int ni = i + di[d], nj = j + dj[d];
            if(inr(0, ni, N) && inr(0, nj, N)) {
                adj[v][deg[v]++] = id(ni, nj);
            }
        }
    }

    array<int, 400> seen{};
    array<int, 400> dist{};
    array<int, 400> bfs_que{};
    int seen_stamp = 0;
    auto calc_reachable_info = [&](const State &s, int rest) {
        if(rest <= 0) return pair<int, int>{0, 0};

        int sum = 0;
        int cnt = 0;
        int head = 0, tail = 0;
        seen_stamp++;
        seen[s.cur] = seen_stamp;
        dist[s.cur] = 0;
        bfs_que[tail++] = s.cur;

        while(head < tail) {
            int v = bfs_que[head++];
            if(dist[v] == rest) continue;

            rep(k, 0, deg[v]) {
                int nv = adj[v][k];
                if(s.visited[nv] || seen[nv] == seen_stamp) continue;
                seen[nv] = seen_stamp;
                dist[nv] = dist[v] + 1;
                sum += value[nv];
                cnt++;
                bfs_que[tail++] = nv;
            }
        }
        return pair<int, int>{sum, cnt};
    };

    auto better = [](const State &l, const State &r) {
        ll l_eval = eval_state(l);
        ll r_eval = eval_state(r);
        if(l_eval != r_eval) return l_eval > r_eval;
        return l.score > r.score;
    };

    vector<State> states;
    states.reserve(NODE_LIMIT);
    QueueItem::states = &states;
    using StaticQueue = StaticPriorityQueue<QueueItem, 20000>;
    vector<StaticQueue> que(T + 1);

    rep(v, 0, V) {
        State s;
        s.cur = v;
        s.score = value[v];
        s.parent = -1;
        s.depth = 1;
        s.visited.set(v);
        auto [reachable_sum, reachable_count] = calc_reachable_info(s, T - 1);
        s.reachable_sum = reachable_sum;
        s.reachable_count = reachable_count;
        states.push_back(s);
        que[1].push(QueueItem{(int)states.size() - 1});
    }

    int best_idx = 0;
    rep(i, 1, (int)states.size()) {
        if(better(states[i], states[best_idx])) best_idx = i;
    }

    TimeKeeper time_keeper(TIME_LIMIT);
    int time_check_counter = 0;
    auto is_time_over_periodic = [&]() {
        time_check_counter++;
        if((time_check_counter & 255) != 0) return false;
        return time_keeper.isTimeOver();
    };

    while(!time_keeper.isTimeOver()) {
        bool updated = false;

        rrep(depth, T - 1, 1) {
            if((int)states.size() >= NODE_LIMIT || is_time_over_periodic()) break;
            if(que[depth].empty()) continue;

            int idx = que[depth].top().idx;
            que[depth].pop();
            const State &s = states[idx];
            updated = true;

            rep(k, 0, deg[s.cur]) {
                int nv = adj[s.cur][k];
                if((int)states.size() >= NODE_LIMIT || is_time_over_periodic()) break;
                if(s.visited[nv]) continue;

                State ns;
                ns.cur = nv;
                ns.score = s.score + value[nv];
                ns.parent = idx;
                ns.depth = s.depth + 1;
                ns.visited = s.visited;
                ns.visited.set(nv);
                auto [reachable_sum, reachable_count] = calc_reachable_info(ns, T - ns.depth);
                ns.reachable_sum = reachable_sum;
                ns.reachable_count = reachable_count;

                states.emplace_back(std::move(ns));
                int new_idx = (int)states.size() - 1;
                auto &next_que = que[states[new_idx].depth];
                if(next_que.size() == QUEUE_MAX_SIZE) {
                    vector<QueueItem> kept;
                    kept.reserve(QUEUE_KEEP_LIMIT);
                    rep(i, 0, QUEUE_KEEP_LIMIT) {
                        kept.push_back(next_que.top());
                        next_que.pop();
                    }
                    next_que.clear();
                    for(const QueueItem &item: kept) next_que.push(item);
                }
                next_que.push(QueueItem{new_idx});
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

    int answer_score = calc_path_score(answer);
    if(zigzag_score > answer_score) {
        answer = zigzag_path;
        answer_score = zigzag_score;
    }
    cerr << "score: " << answer_score << '\n';

    cout << answer.size() << '\n';
    for(int v: answer) {
        auto [i, j] = pos(v);
        cout << i << ' ' << j << '\n';
    }
    
    return 0;
}
