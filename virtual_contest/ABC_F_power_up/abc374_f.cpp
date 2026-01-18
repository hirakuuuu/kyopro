#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// using mint = modint1000000007;
// using mint2 = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;
constexpr ll MOD = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int n, k; cin >> n >> k;
    ll x; cin >> x;
    vector<ll> t(n);
    vector<ll> acc(n+1);
    vector<ll> event = {-x};
    rep(i, 0, n){
        cin >> t[i];
        event.push_back(t[i]);
        rep(j, 1, n+1) event.push_back(t[i]+x*j);
        acc[i+1] = acc[i]+t[i];
    }
    sort(event.begin(), event.end());
    event.erase(unique(event.begin(), event.end()), event.end());
    int m = event.size();

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, INF));
    dp[0][0] = 0;
    rep(i, 0, n){
        rep(j, 0, m){
            if(dp[i][j] == INF) continue;

            int l = i;
            rep(r, i+1, min(i+k, n)+1){
                // [l, r) を運ぶと決めると運ぶべき時間が決まる
                ll time = max(event[j]+x, t[r-1]);
                int s = lower_bound(event.begin(), event.end(), time)-event.begin();
                ll sum = acc[r]-acc[l];
                chmin(dp[r][s], dp[i][j]+(r-l)*time-sum);
            }
        }
        // rep(j, 0, m){
        //     cout << dp[i+1][j] << ' ';
        // }
        // cout << endl;
    }

    ll ans = INF;
    // 運びきれてる
    rep(i, 0, m) chmin(ans, dp[n][i]);

    cout << ans << endl;

    return 0;
}