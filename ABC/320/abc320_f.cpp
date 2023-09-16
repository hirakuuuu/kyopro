#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc320/tasks/abc320_f

int main(){
    ll n, h; cin >> n >> h;
    vector<ll> x(n+1);
    rep(i, 1, n+1) cin >> x[i];
    vector<ll> p(n+1), f(n+1);
    rep(i, 1, n) cin >> p[i] >> f[i];

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(h+1, vector<ll>(h+1, INF)));
    dp[0][][h] = 0;
    rep(i, 1, n+1){
        vector<ll> min_(h+1);
        rep(j, 0, h+1){
            rep(k, 0, i){
                min_
            }
        }
        rep(j, 0, i){
            rep(k, 0, h+1){
                dp[i][j][k] = min(dp[l][j][k] for l in 
            }
        }
    }


    return 0;
}