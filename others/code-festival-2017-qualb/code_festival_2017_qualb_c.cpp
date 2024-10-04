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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
グラフが二部グラフでない　→　奇数長のサイクルが存在する　→  任意の２頂点間に奇数長のパスが存在する
*/

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<vector<int>> seen(2, vector<int>(n));
    queue<pair<int, int>> que;
    que.push({0, 0});
    seen[0][0] = 1;
    while(!que.empty()){
        auto [oe, pos] = que.front(); que.pop();
        for(auto nxt: g[pos]){
            if(seen[1-oe][nxt]) continue;
            seen[1-oe][nxt] = 1;
            que.push({1-oe, nxt});
        }
    }
    vector<int> sum(2);
    rep(i, 0, 2){
        rep(j, 0, n){
            sum[i] += seen[i][j];
        }
    }

    ll ans = 0;
    rep(i, 0, n){
        if(seen[0][i] && seen[1][i]){
            ans += (ll)n-1;
        }else if(seen[0][i]){
            ans += (ll)sum[1];
        }else{
            ans += (ll)sum[0];
        }
    }
    ans /= 2;
    cout << ans-m << endl;
    return 0;
}