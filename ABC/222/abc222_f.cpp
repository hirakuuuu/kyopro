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
// https://atcoder.jp/contests/abc222/tasks/abc222_f

struct Rerooting {

    const ll identity = 0LL;
    ll merge (ll dp_cum, ll d){
        return max(dp_cum, d);
    }
    ll add_root(ll d){
        return d;
    }

    struct Edge {
        int to;
        ll cost;
    };
    using Graph = vector<vector<Edge>>;

    vector<vector<ll>> dp;
    vector<ll> ans;
    vector<ll> d;
    Graph G;

    Rerooting(int n, vector<ll> d_): G(n), d(d_) {
        dp.resize(n);
        ans.assign(n, identity);
    }

    void add_edge(int a, int b, ll c){
        G[a].push_back({b, c});
    }

    void build(){
        dfs(0);
        bfs(0, identity);
    }

    ll dfs(int v, int p = -1){
        ll dp_cum = d[v];
        int deg = G[v].size();
        dp[v] = vector<ll>(deg, dp_cum);
        for(int i = 0; i < deg; i++){
            int u = G[v][i].to;
            if(u == p) continue;
            ll cost = G[v][i].cost;
            dp[v][i] = dfs(u, v)+cost;
            dp_cum = merge(dp_cum, dp[v][i]);
        }
        return dp_cum;
    }

    void bfs(int v, const ll& dp_p, int p = -1){
        int deg = G[v].size();
        ans[v] = dp_p;
        // for(int i = 0; i < deg; i++){
        //     if(G[v][i].to == p) dp[v][i] = dp_p;
        // }
        vector<ll> dp_l(deg+1, identity), dp_r(deg+1, identity);
        for(int i = 0; i < deg; i++){
            if(G[v][i].to != p) dp_l[i+1] = merge(dp_l[i], dp[v][i]);
            else dp_l[i+1] = merge(dp_l[i], dp_p);
        }
        for(int i = deg-1; i >= 0; i--){
            if(G[v][i].to != p) dp_r[i] = merge(dp_r[i+1], dp[v][i]);
            else dp_r[i] = merge(dp_r[i+1], dp_p);
        }

        for(int i = 0; i < deg; i++){
            int u = G[v][i].to;
            if(u == p) continue;
            ll cost = G[v][i].cost;
            ans[v] = merge(ans[v], dp[v][i]);
            bfs(u, max({dp_l[i], dp_r[i+1], dp_p, d[v]})+cost, v);
        }
    }
};

int main(){
    int n; cin >> n;
    vector<int> u(n-1), v(n-1);
    vector<ll> w(n-1);
    rep(i, 0, n-1){
        cin >> u[i] >> v[i] >> w[i];
        u[i]--;
        v[i]--;
    }
    vector<ll> d(n);
    rep(i, 0, n) cin >> d[i];
    Rerooting reroot(n, d);
    rep(i, 0, n-1){
        reroot.add_edge(u[i], v[i], w[i]);
        reroot.add_edge(v[i], u[i], w[i]);
    }
    reroot.build();

    rep(i, 0, n){
        cout << reroot.ans[i] << '\n';
    }
    
    return 0;
}