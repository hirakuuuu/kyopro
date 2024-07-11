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
このように複数回動作を行える場合であっても、1回だけ動作を行うことで連鎖的に複数回の操作をカバーできたりする。
*/


const ll mx = 2500;
int main(){

    int n, m;
    ll s; cin >> n >> m >> s;
    chmin(s, mx);
    vector<vector<tuple<ll, ll, ll>>> g(n);
    rep(i, 0, m){
        int u, v;
        ll a, b; cin >> u >> v >> a >> b;
        u--, v--;
        g[u].push_back({v, a, b});
        g[v].push_back({u, a, b});
    }
    vector<ll> c(n), d(n);
    rep(i, 0, n) cin >> c[i] >> d[i];

    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
    vector<vector<ll>> dist(n, vector<ll>(mx+1, INF));
    que.push({0, 0, s});
    dist[0][s] = 0;
    while(!que.empty()){
        auto [di, u, cnt] = que.top(); que.pop();
        if(dist[u][cnt] < di) continue;
        if(dist[u][min(mx, cnt+c[u])] > di+d[u]){
            dist[u][min(mx, cnt+c[u])] = di+d[u];
            que.push({dist[u][min(mx, cnt+c[u])], u, min(mx, cnt+c[u])});   
        }
        for(auto [v, a, b]: g[u]){
            if(a <= cnt && dist[v][cnt-a] > di+b){
                dist[v][cnt-a] = di+b;
                que.push({dist[v][cnt-a], v, cnt-a});
            }
        }
    }

    rep(i, 1, n){
        ll ans = INF;
        rep(j, 0, mx+1){
            chmin(ans, dist[i][j]);
        }
        cout << ans << endl;
    }

    
    return 0;
}