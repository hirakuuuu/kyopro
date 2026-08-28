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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    rep(i, 0, n){
        cin >> a[i] >> b[i];
    }

    vector<ll> dp(2*k+1, -INF);
    dp[0] = 0;
    rep(i, 0, n){
        vector<ll> ndp(2*k+1, -INF);
        rep(j, 0, 2*k+1){
            if(j%2 == 0) chmax(ndp[j], dp[j]+a[i]);
            else chmax(ndp[j], dp[j]+b[i]);

            if(j != 0){
                if(j%2 == 0) chmax(ndp[j], dp[j-1]+a[i]);
                else chmax(ndp[j], dp[j-1]+b[i]);
            }
        }
        swap(dp, ndp);
    }

    ll ans = -1;
    rep(i, 0, 2*k+1) chmax(ans, dp[i]);
    cout << ans << endl;
    
    return 0;
}