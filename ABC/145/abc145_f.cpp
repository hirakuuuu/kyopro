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
// https://atcoder.jp/contests/abc145/tasks/abc145_f

int main(){
    int n, k; cin >> n >> k;
    vector<ll> h(n);
    rep(i, 0, n) cin >> h[i];
    vector<ll> c(n+1);
    rep(i, 0, n) c[i] = h[i];
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    int m = c.size();
    map<ll, int> id;
    rep(i, 0, m) id[c[i]] = i;

    vector<vector<vector<ll>>> dp(n+5, vector<vector<ll>>(k+5, vector<ll>(n+5, INF)));
    dp[0][0][id[h[0]]] = h[0];
    rep(i, 0, m) dp[0][1][i] = c[i];

    rep(i, 1, n){
        rep(j, 0, min(k, i+1)+1){
            
            vector<ll> mh(m), Mh(m);
            // i番目の高さを変更しない場合
            mh[id[0]] = dp[i-1][j][id[0]];
            rep(l, 1, m){
                mh[l] = min({mh[l-1]+(c[l]-c[l-1]), dp[i-1][j][l]});
            }
            Mh[m-1] = dp[i-1][j][m-1];
            rrep(l, m-2, 0) Mh[l] = min(Mh[l+1], dp[i-1][j][l]);
            chmin(dp[i][j][id[h[i]]], min(mh[id[h[i]]], Mh[id[h[i]]]));

            // i番目の高さを変更する場合
            if(j > 0){
                mh[0] = dp[i-1][j-1][0];
                rep(l, 1, m){
                    mh[l] = min({mh[l-1]+(c[l]-c[l-1]), dp[i-1][j-1][l]});
                }
                Mh[m-1] = dp[i-1][j-1][m-1];
                rrep(l, m-2, 0) Mh[l] = min(Mh[l+1], dp[i-1][j-1][l]);
                rep(l, 0, m){
                    // cout << i << ' ' << j << ' ' << l << ' ' << mh[l] << ' ' << Mh[l] << endl;
                    chmin(dp[i][j][l], min(mh[l], Mh[l]));
                }
            }
        }
    }
    ll ans = INF;
    rep(i, 0, m) chmin(ans, dp[n-1][k][i]);
    cout << ans << endl;
    return 0;
}