#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc277/tasks/abc277_e

vector<vector<vector<int>>> g(2, vector<vector<int>>(200005));
vector<bool> s(200005);

vector<vector<int>> dijk(int start, int a){
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> que;
    vector<vector<int>> dist(2, vector<int>(200005, 1e9));
    que.push({0, start, a});
    dist[a][start] = 0;
    while(!que.empty()){
        vector<int> q = que.top(); que.pop();
        int d = q[0], u = q[1], aa = q[2];
        if(dist[aa][u] < d) continue;
        if(s[u]){
            rep(i, 0, 2){
                for(auto nq: g[i][u]){
                    int v = nq, cost = 1;
                    if(dist[i][v] > d+cost){
                        dist[i][v] = d+cost;
                        que.push({dist[i][v], v, i});
                    }
                }
            }
        }else{
            for(auto nq: g[aa][u]){
                int v = nq, cost = 1;
                if(dist[aa][v] > d+cost){
                    dist[aa][v] = d+cost;
                    que.push({dist[aa][v], v, aa});
                }
            }
        }
    }
    return dist;
}

int main(){
    int n, m, k; cin >> n >> m >> k;
    rep(i, 0, m){
        int u, v, a; cin >> u >> v >> a;
        g[a][u].push_back(v);
        g[a][v].push_back(u);
    }

    rep(i, 0, k){
        int t; cin >> t;
        s[t] = true;
    }

    vector<vector<int>> dist = dijk(1, 1);

    int ans = min(dist[1][n], dist[0][n]);
    if(ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;


    
    return 0;
}