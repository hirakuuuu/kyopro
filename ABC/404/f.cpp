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

int main(){
    int n, t, m, k; cin >> n >> t >> m >> k;

    vector<vector<int>> cnt;
    {
        vector<int> tmp;
        auto f = [&](auto self, int pre, int sum) -> void {
            if(tmp.size() > n) return;
            if(sum == m){
                cnt.push_back(tmp);
            }
            rep(i, pre, m-sum+1){
                tmp.push_back(i);
                self(self, i, sum+i);
                tmp.pop_back();
            }
        };
        f(f, 1, 0);
    }
    // cout << cnt.size() << endl;
    // for(auto cc: cnt){
    //     for(auto c: cc){
    //         cout << c << ' ';
    //     }
    //     cout << endl;
    // }

    vector<vector<long double>> dp(t+1, vector<long double>(k+1));
    dp[0][0] = 1.0;
    rep(i, 1, t+1){
        rep(j, 0, k+1){
            for(auto c: cnt){
                long double pr = 0.0;
                for(auto cc: c){
                    pr += dp[i-1][max(0, j-cc)]/(long double)n;
                }
                pr += dp[i-1][j]*(1.0-(long double)c.size()/(long double)n);
                chmax(dp[i][j], pr);
            }
        }
        // cout << "############ i=" << i << " #############" << endl;
        // rep(j, 0, k+1){
        //     cout << "j = " << j << ": " << dp[i][j] << endl;
        // }
    }

    cout << setprecision(20) << dp[t][k] << endl;

    return 0;
}