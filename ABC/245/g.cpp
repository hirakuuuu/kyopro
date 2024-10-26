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

/*
国が異なるかつ近い上位2頂点への距離を管理できれば、ダイクストラ的な感じで解けそう

*/


int main(){
    int n, m, k, l; cin >> n >> m >> k >> l;
    vector<int> a(n), b(l);
    rep(i, 0, n){
        cin >> a[i];
        a[i]--;
    }
    rep(i, 0, l){
        cin >> b[i];
        b[i]--;
    }

    vector<vector<pair<int, ll>>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        ll c; cin >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    vector<vector<pair<ll, ll>>> dist(n, vector<pair<ll, ll>>(2, {INF, -1}));
    auto dijk = [&]() -> void {
        priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
        // 人気者の頂点をすべて追加する
        rep(i, 0, l){
            que.push({0LL, b[i], a[b[i]]});
            dist[b[i]][0] = {0LL, a[b[i]]};
        }
        while(!que.empty()){
            auto [d, u, c] = que.top(); que.pop();
            bool ok = false;
            rep(i, 0, 2){
                auto [cd, cc] = dist[u][i];
                if(cd == d && cc == c) ok = true;
            }
            if(!ok) continue;

            for(auto [v, cost]: g[u]){
                rep(i, 0, 2){
                    auto [d1, c1] = dist[v][i];
                    if(c1 == c){
                        if(d1 > d+cost){
                            dist[v][i] = {d+cost, c};
                            que.push({d+cost, v, c});
                        }
                        break;
                    }else if(i == 0){
                        if(d1 > d+cost){
                            dist[v][0] = {d+cost, c};
                            que.push({d+cost, v, c});
                            dist[v][1] = {d1, c1};
                            break;
                        }
                    }else{
                        if(d1 > d+cost){
                            dist[v][i] = {d+cost, c};
                            que.push({d+cost, v, c});
                        }
                    }
                }
            }
        }
    };

    dijk();
    rep(i, 0, n){
        ll ans = INF;
        rep(j, 0, 2){
            auto [d, c] = dist[i][j];
            if(a[i] != c) chmin(ans, d);
        }
        if(ans == INF) cout << -1 << ' ';
        else cout << ans << ' ';
    }
    cout << endl;

    return 0;
}