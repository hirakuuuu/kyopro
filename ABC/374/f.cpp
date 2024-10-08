#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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
    ll n, k; cin >> n >> k;
    ll x; cin >> x;
    vector<ll> t(n);
    rep(i, 0, n) cin >> t[i];
    vector<ll> acc(n+1);
    rep(i, 0, n) acc[i+1] = acc[i]+t[i];

    ll ans = INF;
    // dp[i][j] := i 番目までの商品を j 個まとめて出荷するときの {コスト, 出荷時刻} の最小値
    vector<vector<pair<ll, ll>>> dp(n+1, vector<pair<ll, ll>>(k+1, {INF, INF}));
    dp[0][0] = {0, -x+1};
    rep(i, 1, n+1){
        rep(j, 1, min(i, k)+1){
            ll l = i-j;
            rep(o, 0, k+1){
                if(dp[l][o].second == INF) continue;
                ll d = max(t[i-1], dp[l][o].second+x);
                chmin(dp[i][j], make_pair(dp[l][o].first+d*j-(acc[i]-acc[l]), d));
            }
        }
    }
    rep(o, 0, k+1){
        chmin(ans, dp[n][o].first);
    }
    cout << ans << endl;

    return 0;
}