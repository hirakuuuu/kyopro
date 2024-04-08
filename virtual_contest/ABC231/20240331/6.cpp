#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    vector<vector<ll>> dp((1<<n), vector<ll>(n, INF));
    rep(i, 0, n){
        dp[(1<<i)][i] = y*i+x*abs(a[i]-b[0]);
    }
    rep(i, 1, 1<<n){
        ll cnt = __popcount(i), offset = 0;
        rep(j, 0, n){
            if(!((i>>j)&1)) continue;
            offset = 0;
            rep(k, 0, n){
                if(!((i>>k)&1)){
                    chmin(dp[i+(1<<k)][k], dp[i][j]+y*offset+x*abs(a[k]-b[cnt]));
                    offset++;
                }
            }
        }
    }
    ll ans = INF;
    rep(i, 0, n) chmin(ans, dp[(1<<n)-1][i]);
    cout << ans << endl;

    return 0;
}