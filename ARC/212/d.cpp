#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

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
    double progress() const {
        using chrono::duration_cast;
        using chrono::milliseconds;
        auto diff = chrono::high_resolution_clock::now() - this->start_time_;
        return static_cast<double>(duration_cast<milliseconds>(diff).count()) / (double)time_threshold_;
    }
};

int main(){
    TimeKeeper time_keeper(TIME_LIMIT);
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> a[i][j];
        }
    }

    vector<int> x(n);
    rep(i, 0, n) x[i] = rand()%2;
    
    auto calc_score = [&](vector<int> &x) -> int {
        int res = 0;
        rep(i, 0, n){
            int sum0 = 0, sum1 = 0;
            rep(j, 0, n){
                if(x[i] == x[j]) sum1 += a[i][j];
                else sum0 += a[i][j];
            }
            res += sum1-sum0;
        }
        return res;
    };

    vector<int> best = x;
    int best_score = calc_score(x);
    while(!time_keeper.isTimeOver()){
        vector<int> cur = best;
        if(rand()%2){
            int pos = rand()%n;
            cur[pos] = 1-cur[pos];
            int new_score = calc_score(cur);
            if(new_score > best_score){
                best = cur;
                best_score = new_score;
            }else{
                cur[pos] = 1-cur[pos];
            }
        }else{
            int p = rand()%n, q = rand()%n;
            rep(_, 0, n){
                if(cur[p] != cur[q]) break;
                p = rand()%n, q = rand()%n;
            }
            if(cur[p] == cur[q]) continue;

            swap(cur[p], cur[q]);
            int new_score = calc_score(cur);
            if(new_score > best_score){
                best = cur;
                best_score = new_score;
            }else{
                swap(cur[p], cur[q]);
            }
        }
    }

    rep(i, 0, n){
        if(best[i]) cout << 'X';
        else cout << 'Y';
    }
    cout << endl;
    return 0;
}