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
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(k+1, vector<ll>(2))); 
    vector<vector<ll>> mx(n, vector<ll>(k+1)); 
    // dp[i][j][l] := i を根とする部分木で i が　(j==0 なら白，j==１なら黒)のとき，l 回操作を行ったうえでのスコアの最大値
    // mx[i][j] := i を根とする部分木で i が白のとき，j 回操作を行ったうえでの i を含むスコア最大のパス
    
    auto f = [&](auto self, int pos, int pre) -> void {
        vector<ll> w(k+1);
        vector<vector<ll>> b(k+1, vector<ll>(3));
        rep(i, 1, k+1) b[i][1] = a[pos];
        vector<ll> m(k+1, a[pos]);
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
            rrep(i, k, 0){
                rep(j, 0, k+1){
                    if(i+j > k) continue;;
                    if(i+j != 0) chmax(b[i+j][2], b[i+j][1]+dp[nxt][j][0]+mx[nxt][j]);
                }
                rrep(j, k, 0){
                    if(i+j > k) continue;
                    if(i+j < k) chmax(b[i+j+1][1], w[i]+dp[nxt][j][0]+mx[nxt][j]+a[pos]);
                }

                rrep(j, k, 0){
                    if(i+j > k) continue;
                    chmax(w[i+j], w[i]+dp[nxt][j][0]);
                    // chmax(w[i+j], w[i]+dp[nxt][j][1]);
                    chmax(m[i+j], mx[nxt][j]+a[pos]);
                }
            }
        }

        rep(i, 0, k+1){
            dp[pos][i][0] = w[i];
            dp[pos][i][1] = max(b[i][1], b[i][2]);
            mx[pos][i] = m[i];
        }

        cout << "########################## pos = " << pos << " #############################" << endl;
        rep(i, 0, 2) rep(j, 0, k+1){
            cout << i << ' ' << j << ' ' << dp[pos][j][i] << ' ' << mx[pos][j] << endl;
        }
    };

    f(f, 0, -1);
    ll ans = 0;
    rep(i, 0, k+1) rep(j, 0, 2){
        chmax(ans, dp[0][i][j]);
    }
    cout << ans << endl;
    return 0;
}