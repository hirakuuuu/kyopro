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
constexpr ll INF = 1e18;
constexpr ll MOD = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int n, m, q; cin >> n >> m >> q;
    vector<tuple<int, int, ll>> edges(m);
    rep(i, 0, m){
        int a, b; cin >> a >> b; a--, b--;
        ll c; cin >> c;
        edges[i] = {a, b, c};
    }
    vector<tuple<int, int, int>> query(q);
    vector<bool> able(m, true);
    rep(i, 0, q){
        int t; cin >> t;
        if(t == 1){
            int id; cin >> id; id--;
            query[i] = {t, id, -1};
            able[id] = false;
        }else{
            int x, y; cin >> x >> y; x--, y--;
            query[i] = {t, x, y};
        }
    }
    
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    rep(i, 0, n) dist[i][i] = 0;
    rep(i, 0, m){
        if(able[i]){
            auto [a, b, c] = edges[i];
            dist[a][b] = dist[b][a] = c;
        }
    }
    rep(k, 0, n) rep(i, 0, n) rep(j, 0, n){
        chmin(dist[i][j], dist[i][k]+dist[k][j]);
    }

    vector<ll> ans;
    rrep(id, q-1, 0){
        auto [t, x, y] = query[id];
        if(t == 1){
            auto [a, b, c] = edges[x];
            if(dist[a][b] > c){
                dist[a][b] = dist[b][a] = c;
                rep(i, 0, n) rep(j, 0, n){
                    chmin(dist[i][j], dist[i][b]+dist[a][j]+c);
                    chmin(dist[i][j], dist[i][a]+dist[b][j]+c);
                }
            }
        }else{
            
            if(dist[x][y] == INF) ans.push_back(-1);
            else ans.push_back(dist[x][y]);
        }
    }

    reverse(ans.begin(), ans.end());
    for(auto aa: ans){
        cout << aa << endl;
    }
    return 0;
}