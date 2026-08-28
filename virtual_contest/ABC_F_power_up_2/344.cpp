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

/*
(最小行動回数，最小行動回数のうち最大あまり)にして良いのは，あまりの部分がそれまでの max 以上になることがない（そうなら行動しないでよい）ことから言える
*/

int main(){
    int n; cin >> n;
    vector<vector<ll>> p(n, vector<ll>(n));
    rep(i, 0, n) rep(j, 0, n) cin >> p[i][j];
    
    vector<vector<ll>> r(n, vector<ll>(n-1));
    vector<vector<ll>> d(n-1, vector<ll>(n));
    rep(i, 0, n) rep(j, 0, n-1) cin >> r[i][j];
    rep(i, 0, n-1) rep(j, 0, n) cin >> d[i][j];

    vector dp(n, vector<unordered_map<ll, pair<ll, ll>>>(n));
    dp[0][0][p[0][0]] = {0, 0};
    rep(i, 0, n){
        rep(j, 0, n){
            if(j < n-1){
                // (i, j) -> (i, j+1). cost: r[i][j]
                for(auto [key, val]: dp[i][j]){
                    auto [cnt, tmp] = val;
                    cnt = -cnt;
                    ll need = (max(0LL, r[i][j]-tmp)+key-1)/key;
                    tmp += need*key;
                    tmp -= r[i][j];
                    cnt += need+1;
                    ll mx = max(key, p[i][j+1]);
                    if(dp[i][j+1].count(mx)){
                        chmax(dp[i][j+1][mx], make_pair(-cnt, tmp));
                    }else{
                        dp[i][j+1][mx] = make_pair(-cnt, tmp);
                    }
                }                
            }
            if(i < n-1){
                // (i, j) -> (i+1, j). cost: d[i][j]
                for(auto [key, val]: dp[i][j]){
                    auto [cnt, tmp] = val;
                    cnt = -cnt;
                    ll need = (max(0LL, d[i][j]-tmp)+key-1)/key;
                    tmp += need*key;
                    tmp -= d[i][j];
                    cnt += need+1;
                    ll mx = max(key, p[i+1][j]);
                    if(dp[i+1][j].count(mx)){
                        chmax(dp[i+1][j][mx], make_pair(-cnt, tmp));
                    }else{
                        dp[i+1][j][mx] = make_pair(-cnt, tmp);
                    }
                }                
            }

            // for(auto [key, val]: dp[i][j]){
            //     cout << i << ", " << j << ", " << key << ": " << -val.first << " " << val.second << endl;
            // }
        }
    }

    ll ans = INF;
    for(auto [key, val]: dp[n-1][n-1]){
        chmin(ans, -val.first);
    }
    cout << ans << endl;
    
    return 0;
}