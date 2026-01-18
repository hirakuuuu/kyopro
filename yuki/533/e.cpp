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
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> a(n);
    int k; cin >> k;
    rep(i, 0, k){
        int A; cin >> A; A--;
        a[A] = 1;
    }

    queue<pair<int, int>> que;
    vector<vector<int>> dist(n, vector<int>(5, IINF));
    dist[0][0] = 0;
    que.push({0, 0});
    while(!que.empty()){
        auto [u, cnt] = que.front(); que.pop();
        for(auto v: g[u]){
            if(cnt+a[v] >= 5) continue;
            if(a[v] == 1){
                if(dist[v][cnt+a[v]] != IINF) continue;
                dist[v][cnt+a[v]] = dist[u][cnt]+1;
                que.push({v, cnt+a[v]});
            }else{
                if(dist[v][0] != IINF) continue;
                dist[v][0] = dist[u][cnt]+1;
                que.push({v, 0});
            }

        }
    }
    int ans = IINF;
    rep(i, 0, 5) chmin(ans, dist[n-1][i]);
    if(ans == IINF) ans = -1;
    cout << ans << endl;
    return 0;
}