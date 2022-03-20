#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n, m; cin >> n >> m;
    int N = 1<<n;

    vector<vector<int>> dist(N, vector<int>(n, 10000));
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }
    queue<pii> que;

    rep(i, 0, n){
        dist[1<<i][i] = 1;
        que.push({1<<i, i});
    }

    while(!que.empty()){
        pii q = que.front(); que.pop();
        for(auto nqs: g[q.second]){
            int nqf = q.first ^ (1<<nqs);
            if(dist[nqf][nqs] < 10000) continue;
            dist[nqf][nqs] = dist[q.first][q.second]+1;
            que.push({nqf, nqs});
        }
    }
    int ans = 0;
    rep(i, 1, N){
        int mp = 10000;
        rep(j, 0, n) mp = min(mp, dist[i][j]);
        ans += mp;
    }
    cout << ans << endl;

}