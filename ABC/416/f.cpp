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

    vector<vector<ll>> dp_0(n, vector<ll>(k+1)); // 根が白
    vector<vector<ll>> dp_1(n, vector<ll>(k+1)); // 根を端点にもつパス
    vector<vector<ll>> dp_2(n, vector<ll>(k+1)); // 根を含むパス
    auto f = [&](auto self, int pos, int pre) -> void {
        rep(i, 0, k+1){
            dp_0[pos][i] = 0;
            if(i > 0) dp_1[pos][i] = dp_2[pos][i] = a[pos];
        }

        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);

            vector<ll> pre_0 = dp_0[pos];
            vector<ll> pre_1 = dp_1[pos];
            vector<ll> pre_2 = dp_2[pos];
            
            // 根を白にする場合
            for(int i = 0; i <= k; i++){
                for(int j = 0; i+j <= k; j++){
                    chmax(dp_0[pos][i+j], pre_0[i]+dp_0[nxt][j]);
                    chmax(dp_0[pos][i+j], pre_0[i]+dp_1[nxt][j]);
                    chmax(dp_0[pos][i+j], pre_0[i]+dp_2[nxt][j]);
                }
            }

            // 根を端点にする場合
            for(int i = 0; i <= k; i++){
                for(int j = 0; i+j <= k; j++){
                    if(i+j+1 <= k){
                        chmax(dp_1[pos][i+j+1], pre_0[i]+dp_0[nxt][j]+a[pos]);
                        chmax(dp_1[pos][i+j+1], pre_0[i]+dp_2[nxt][j]+a[pos]);
                    }
                    if(i >= 1){
                        chmax(dp_1[pos][i+j], pre_1[i]+dp_0[nxt][j]);
                        chmax(dp_1[pos][i+j], pre_1[i]+dp_1[nxt][j]);
                        chmax(dp_1[pos][i+j], pre_1[i]+dp_2[nxt][j]);
                    }
                    if(j >= 1) chmax(dp_1[pos][i+j], pre_0[i]+dp_1[nxt][j]+a[pos]);
                }
            }

            // 根を含む場合
            for(int i = 0; i <= k; i++){
                for(int j = 0; j <= k && i+j <= k+1; j++){
                    if(i >= 1 && j >= 1){
                        chmax(dp_2[pos][i+j-1], pre_1[i]+dp_1[nxt][j]);
                    }
                    if(i+j <= k){
                        chmax(dp_2[pos][i+j], pre_2[i]+dp_0[nxt][j]);
                        chmax(dp_2[pos][i+j], pre_2[i]+dp_1[nxt][j]);
                        chmax(dp_2[pos][i+j], pre_2[i]+dp_2[nxt][j]);
                    }
                }
            }
        }

        // cout << "################# pos = " << pos << " #################" << endl;
        // rep(i, 0, k+1){
        //     cout << pos << " " << dp_0[pos][i] << ' ' << dp_1[pos][i] << ' ' << dp_2[pos][i] << endl;
        // }
    };

    f(f, 0, -1);

    ll ans = 0;
    rep(i, 0, k+1){
        chmax(ans, dp_0[0][i]);
        chmax(ans, dp_1[0][i]);
        chmax(ans, dp_2[0][i]);
    }
    cout << ans << endl;
    return 0;
}