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
    int n; cin >> n;
    vector<ll> A(n);
    rep(i, 0, n) cin >> A[i];
    ll d = 0;
    rep(i, 2, n) d ^= A[i];

    // (a[0]-x)^(a[1]+x) = c にできるか（0 <= x < a[0]）
    // 上の桁に対する操作が下の桁に影響を与えないので, 下の桁から順番に考えることができそう
    // 繰り上がりや繰り下がりが生じているかを持っておけば, 桁DPができる

    // vector<vector<vector<ll>>> dp(51, vector<vector<ll>>(2, vector<ll>(2, INF)));
    // dp[0][0][0] = 0;
    // rep(i, 0, 50) rep(j, 0, 2) rep(k, 0, 2){
    //     ll a0 = ((a[0]&(1LL<<i)) != 0);
    //     ll a1 = ((a[1]&(1LL<<i)) != 0);
    //     ll b = ((c&(1LL<<i)) != 0);
        
    //     int jj = 0, kk = 0;
    //     if(j){
    //         a0--;
    //         if(a0 < 0){ a0 = 1; jj = 1; }
    //     }
    //     if(k){
    //         a1++;
    //         if(a1 == 2){ a1 = 0; kk = 1; }
    //     }

    //     if((a0^a1) == b) chmin(dp[i+1][jj][kk], dp[i][j][k]);

    //     a0--;
    //     if(a0 < 0){ jj = 1; a0 = 1; }
    //     a1++;
    //     if(a1 >= 2){ kk = 1; a1 = 0; }
    //     if((a0^a1) == b) chmin(dp[i+1][jj][kk], dp[i][j][k]+(1LL<<i));
    // }
    // ll ans = dp[50][0][0];
    // if(ans == INF || ans == a[0]) cout << -1 << endl;
    // else cout << ans << endl;

    map<tuple<ll, ll, ll>, ll> memo;
    auto f = [&](auto self, ll a, ll b, ll c) -> ll {
        if(memo.find({a, b, c}) != memo.end()) return memo[{a, b, c}];
        if(a == 0){
            if(b == c) return 0;
            return INF;
        }

        ll res = INF;
        if(((a&1)^(b&1)) == (c&1)) chmin(res, 2*self(self, a/2, b/2, c/2));
        if((((a-1)&1)^((b+1)&1)) == (c&1)) chmin(res, 2*self(self, (a-1)/2, (b+1)/2, c/2)+1);
        // cout << a << ' ' << b << ' ' << c << ' ' << res << endl;
        return memo[{a, b, c}] = res;
    };

    ll ans = f(f, A[0], A[1], d);
    if(ans == INF || ans == A[0]) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}