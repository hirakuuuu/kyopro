#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc148/tasks/abc148_f

void dfs(int pos, int pre, vector<vector<int>> &g, vector<int> &height){
    for(auto npos: g[pos]){
        if(npos == pre) continue;
        height[npos] = height[pos]+1;
        dfs(npos, pos, g, height);
    }
}

int main(){
    int n, u, v; cin >> n >> u >> v;
    u--, v--;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> height(n);
    dfs(v, -1, g, height);
    vector<int> dist(n, -1);
    dist[u] = 0;
    queue<int> que;
    que.push(u);
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(dist[nq] != -1) continue;
            if(dist[q]+1 >= height[nq]) continue;
            dist[nq] = dist[q]+1;
            que.push(nq);
        }
    }

    int ans = 0;
    rep(i, 0, n){
        if(dist[i] == -1) continue;
        int t = height[i], a = dist[i];
        chmax(ans, a+(t-a)-1);
    }
    cout << ans << endl;


    
    return 0;
}