#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc289/tasks/abc289_e


int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> c(n+1);
        vector<vector<int>> g(n+1);
        rep(i, 1, n+1) cin >> c[i];
        rep(i, 0, m){
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> dist(n*n, iinf);
        queue<int> que;
        que.push(n-1);
        dist[n-1] = 0;
        while(!que.empty()){
            int q = que.front(); que.pop();
            int ta = q/n+1, ao = q%n+1;
            for(auto tt: g[ta]){
                for(auto aa: g[ao]){
                    if(dist[tt*n+aa-n-1] != iinf or c[tt] == c[aa]) continue;
                    que.push(tt*n+aa-n-1);
                    dist[tt*n+aa-n-1] = dist[q]+1;
                }
            }
        }
        if(dist[n*n-n] == iinf) cout << -1 << endl;
        else cout << dist[n*n-n] << endl;
    }
    
    return 0;
}