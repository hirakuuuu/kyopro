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
// https://atcoder.jp/contests/agc012/tasks/agc012_b

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int q; cin >> q;
    vector<int> u(q), d(q), c(q);
    rep(i, 0, q){
        cin >> u[i] >> d[i] >> c[i];
        u[i]--;
    }

    vector<vector<int>> dp(n, vector<int>(11));
    auto f = [&](auto self, int pos, int dist, int color) -> void {
        if(dp[pos][dist] != 0) return;
        rep(i, 0, dist+1){
            if(dp[pos][i] != 0) continue;
            dp[pos][i] = color;
        }
        if(dist == 0) return;
        for(auto nxt: g[pos]){
            self(self, nxt, dist-1, color);
        }
    };
    rrep(i, q-1, 0){
        f(f, u[i], d[i], c[i]);
    }
    rep(i, 0, n){
        cout << dp[i][0] << ' '; 
    }
    cout << endl;

    
    return 0;
}