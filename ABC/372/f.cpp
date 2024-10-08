#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> x(m), y(m);
    rep(i, 0, m){
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
    }

    vector<mint> dp(n);
    dp[0] = 1;
    int rotate = 0;
    rep(j, 1, k+1){
        vector<mint> pre(m);
        rep(i, 0, m){
            pre[i] = dp[(x[i]+n-rotate)%n];
        }
        rotate = (rotate+1)%n;
        rep(i, 0, m){
            dp[(y[i]+n-rotate)%n] += pre[i];
        }
        // rep(i, 0, n){
        //     cout << dp[(i+n-rotate)%n].val() << ' ';
        // }
        // cout << endl;
    }
    mint ans = 0;
    rep(i, 0, n) ans += dp[i];
    cout << ans.val() << endl;

    return 0;
}