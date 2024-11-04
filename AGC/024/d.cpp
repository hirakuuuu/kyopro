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
    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<vector<int>> dist(n, vector<int>(n, IINF));
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        dist[a][b] = dist[b][a] = 1;
    }
    
    rep(i, 0, n) dist[i][i] = 0;
    int diameter = 0, s = -1, t = -1;
    rep(k, 0, n){
        rep(i, 0, n) rep(j, 0, n){
            chmin(dist[i][j], dist[i][k]+dist[k][j]);
            if(dist[i][j] != IINF && diameter < dist[i][j]){
                diameter = dist[i][j];
                s = i, t = j;
            }
        }
    }


    // 中心
    vector<int> center;
    rep(i, 0, n){
        if(max(dist[i][s], dist[i][t]) == (diameter+1)/2 && min(dist[i][s], dist[i][t]) == diameter/2) center.push_back(i);
    }

    assert(center.size() >= 1 && center.size() <= 2);
    ll min_leaf;
    if(center.size() == 1){
        min_leaf = INF;
        for(auto v: g[center[0]]){
            ll tmp = 2;
            vector<int> mx(n);
            rep(i, 0, n){
                chmax(mx[min(dist[center[0]][i], dist[v][i])], (int)g[i].size()-1);
            }
            rep(i, 0, n){
                if(mx[i] == 0) break;
                tmp *= mx[i];
            }
            chmin(min_leaf, tmp);
        }
        {
            ll tmp = 1;
            vector<int> mx(n);
            rep(i, 0, n){
                if(i == center[0]) chmax(mx[dist[center[0]][i]], (int)g[i].size());
                else chmax(mx[dist[center[0]][i]], (int)g[i].size()-1);
            }
            rep(i, 0, n){
                if(mx[i] == 0) break;
                tmp *= mx[i];
            }
            chmin(min_leaf, tmp);
        }
    }else{
        min_leaf = 2;
        vector<int> mx(n);
        rep(i, 0, n){
            chmax(mx[min(dist[center[0]][i], dist[center[1]][i])], (int)g[i].size()-1);
        }
        rep(i, 0, n){
            if(mx[i] == 0) break;
            min_leaf *= mx[i];
        }
    }
    cout << (diameter+2)/2 << ' ' << min_leaf << endl;
    
    return 0;
}