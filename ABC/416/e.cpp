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
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, INF));
    rep(i, 0, n+1){
        dist[i][i] = 0;
    }
    rep(i, 0, m){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        chmin(dist[a][b], c);
        chmin(dist[b][a], c);
    }
    int k; cin >> k;
    ll T; cin >> T;
    vector<int> d(k);
    rep(i, 0, k){
        cin >> d[i], d[i]--;
        dist[d[i]][n] = 0;
        dist[n][d[i]] = T;
    }

    rep(l, 0, n+1) rep(i, 0, n+1) rep(j, 0, n+1){
        chmin(dist[i][j], dist[i][l]+dist[l][j]);
    }
    ll f = 0;
    rep(i, 0, n) rep(j, 0, n){
        if(dist[i][j] == INF) continue;
        // cout << i << ' ' << j << ' ' << dist[i][j] << endl;
        f += dist[i][j];
    }
    // cout << f << endl;

    int q; cin >> q;
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int x, y, t; cin >> x >> y >> t;
            x--, y--;
            rep(i, 0, n+1) rep(j, 0, n+1){
                if(i != n && j != n && dist[i][j] != INF) f -= dist[i][j];
                chmin(dist[i][j], dist[i][x]+t+dist[y][j]);
                chmin(dist[i][j], dist[i][y]+t+dist[x][j]);
                if(i != n && j != n && dist[i][j] != INF) f += dist[i][j];
            }
        }else if(op == 2){
            int x; cin >> x; x--;
            dist[x][n] = 0;
            dist[n][x] = T;
            rep(i, 0, n+1) rep(j, 0, n+1){
                if(i != n && j != n && dist[i][j] != INF) f -= dist[i][j];
                chmin(dist[i][j], dist[i][n]+dist[n][x]+dist[x][j]);
                chmin(dist[i][j], dist[i][x]+dist[x][n]+dist[n][j]);
                if(i != n && j != n && dist[i][j] != INF) f += dist[i][j];
            }
        }else{
            cout << f << endl;
        }
    }



    return 0;
}