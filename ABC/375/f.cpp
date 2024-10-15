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
    int n, m, q; cin >> n >> m >> q;
    vector<tuple<int, int, ll>> edges(m);
    rep(i, 0, m){
        int a, b; cin >> a >> b; a--, b--;
        ll c; cin >> c;
        edges[i] = {a, b, c};
    }
    vector<tuple<int, int, int>> query(q);
    vector<bool> closed(m);
    rep(i, 0, q){
        int t; cin >> t;
        if(t == 1){
            int id; cin >> id; id--;
            query[i] = {t, id, -1};
            closed[id] = true;
        }else{
            int x, y; cin >> x >> y; x--, y--;
            query[i] = {t, x, y};
        }
    }
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    rep(i, 0, n) dist[i][i] = 0;
    rep(i, 0, m){
        if(closed[i]) continue;
        auto [a, b, c] = edges[i];
        dist[a][b] = dist[b][a] = c;
    }
    rep(k, 0, n){
        rep(i, 0, n){
            rep(j, 0, n){
                chmin(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    vector<ll> ans;
    rrep(i, q-1, 0){
        auto [t, x, y] = query[i];
        if(t == 1){
            // x が通行止めでなくなる
            auto [a, b, c] = edges[x];
            rep(j, 0, n){
                rep(k, 0, n){
                    chmin(dist[j][k], min(dist[j][a]+dist[b][k], dist[j][b]+dist[a][k])+c);
                }
            }
        }else{
            ans.push_back(dist[x][y]);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto a: ans){
        if(a == INF) cout << -1 << endl;
        else cout << a << endl;
    }

    
    return 0;
}