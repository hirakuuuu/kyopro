#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n){
        int j, k; cin >> j >> k;
        rep(l, 0, k){
            int v; cin >> v;
            g[j-1].push_back(v-1);
        }
    }
    vector<int> dist(n, -1);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(dist[nq] == -1){
                dist[nq] = dist[q]+1;
                que.push(nq);
            }
        }
    }

    rep(i, 0, n){
        printf("%d %d\n", i+1, dist[i]);
    }
}