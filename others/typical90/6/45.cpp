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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
ビットの部分集合
for(int s = i; ; s = (s-1)&i){
    if(s == 0) break; // 空集合を含めるか
    // 差集合は s-i で取れる
}
計算量 O(3^n)
*/


int main(){
    int n, k; cin >> n >> k;
    vector<ll> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];
    auto dist = [&](int i, int j) -> ll {
        return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    };
    vector<ll> mx(1<<n);
    rep(i, 1, 1<<n){
        rep(j, 0, n){
            if(!((i>>j)&1)) continue;
            rep(l, j+1, n){
                if(!((i>>l)&1)) continue;
                chmax(mx[i], dist(j, l));
            }
        }
    }

    vector<vector<ll>> dp(k+1, vector<ll>(1<<n, INF));
    dp[0][0] = 0LL;
    rep(i, 1, k+1){
        rep(j, 1, 1<<n){
            for(int s = j; s != 0; s = (s-1)&j){
                chmin(dp[i][j], max(mx[s], dp[i-1][j-s]));
            }
        }
    }
    cout << dp[k][(1<<n)-1] << endl;

    return 0;
}