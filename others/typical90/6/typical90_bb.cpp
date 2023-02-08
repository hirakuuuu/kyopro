#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_bb

// 論文と研究者をノードとするように辺を結べば大幅に辺を削減できる

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n+m);
    rep(i, 0, m){
        int k; cin >> k;
        rep(j, 0, k){
            int v; cin >> v; v--;
            g[v].push_back(n+i);
            g[n+i].push_back(v);
        }
    }

    queue<int> que;
    que.push(0);
    vector<int> dist(n+m, -2);
    dist[0] = 0;
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto &nq: g[q]){
            if(dist[nq] == -2){
                dist[nq] = dist[q]+1;
                que.push(nq);
            }
        }
    }

    rep(i, 0, n){
        cout << dist[i]/2 << '\n';
    }
    
    return 0;
}