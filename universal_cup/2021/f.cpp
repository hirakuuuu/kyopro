#pragma GCC optimize ("O3,inline,omit-frame-pointer,no-asynchronous-unwind-tables,fast-math")

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

pair<int, int> dist1[100005][50];
pair<int, int> dist2[100005][50];

int main(){
    ios::sync_with_stdio(false);  // 高速入出力
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        vector<int> c(n);
        int mx_c = 0;
        rep(i, 0, n) cin >> c[i], c[i]--, chmax(mx_c, c[i]+1);

        // vector<vector<pair<int, int>>> dist1(n, vector<pair<int, int>>(mx_c, {IINF, IINF}));
        // vector<vector<pair<int, int>>> dist2(n, vector<pair<int, int>>(mx_c, {IINF, IINF+1}));
        rep(i, 0, n){
            rep(j, 0, mx_c){
                dist1[i][j] = {IINF, IINF};
                dist2[i][j] = {IINF, IINF+1};
            }
        }
        vector<pair<int, int>> edges(m);
        rep(i, 0, m){
            int u, v; cin >> u >> v;
            u--, v--;
            if(u != v){
                if(dist1[u][c[v]].first == IINF) dist1[u][c[v]] = {2, v};
                else if(dist1[u][c[v]].second != v) dist2[u][c[v]] = {2, v};
            }
            edges[i] = {u, v};
        }

        rep(_, 0, 50){
            int f = 0;
            rep(i, 0, m){
                auto [u, v] = edges[i];
                if(u == v) continue;
                rep(j, 0, mx_c){
                    if(dist1[v][j].first <= mx_c && dist1[v][j].second != u){
                        // pair<int, int> d1 = dist1[u][j], d2 = dist2[u][j];
                        pair<int, int> d3 = dist1[v][j];
                        d3.first++;
                        if(d3.first < dist1[u][j].first){
                            if(d3.second != dist1[u][j].second) dist2[u][j] = dist1[u][j], dist1[u][j] = d3;
                            else dist1[u][j] = d3;
                            f = 1;
                        }else if(d3.first < dist2[u][j].first){
                            if(d3.second != dist1[u][j].second) dist2[u][j] = d3, f = 1;
                        }
                    }
                    if(dist2[v][j].first <= mx_c && dist2[v][j].second != u){
                        // pair<int, int> d1 = dist1[u][j], d2 = dist2[u][j];
                        pair<int, int> d3 = dist2[v][j];
                        d3.first++;
                        if(d3.first < dist1[u][j].first){
                            if(d3.second != dist1[u][j].second) dist2[u][j] = dist1[u][j], dist1[u][j] = d3;
                            else dist1[u][j] = d3;
                            f = 1;
                        }else if(d3.first < dist2[u][j].first){
                            if(d3.second != dist1[u][j].second) dist2[u][j] = d3, f = 1;
                        }
                    }
                }
            }
            if(!f) break;
        }

        bool ok = true;
        rep(i, 0, n){
            if(dist1[i][c[i]].first <= k && dist1[i][c[i]].second != i) ok = false;
            if(dist2[i][c[i]].first <= k && dist2[i][c[i]].second != i) ok = false;
        }
        if(ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';




        
    }
    return 0;
}