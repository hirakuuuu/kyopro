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
// 

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dist(n, IINF);
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    int ns = 0, max_d = 0;
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(dist[nq] != IINF) continue;
            dist[nq] = dist[q]+1;
            if(max_d < dist[nq]){
                max_d = dist[nq];
                ns = nq;
            }
            que.push(nq);
        }
    }

    fill(dist.begin(), dist.end(), IINF);
    dist[ns] = 0;
    que.push(ns);
    ns = 0, max_d = 0;
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(dist[nq] != IINF) continue;
            dist[nq] = dist[q]+1;
            if(max_d < dist[nq]){
                max_d = dist[nq];
                ns = nq;
            }
            que.push(nq);
        }
    }

    vector<int> dp(n+1);
    dp[1] = 0;
    dp[2] = 1;
    rep(i, 3, n+1){
        dp[i] = 1-(dp[i-1] | dp[i-2]);
    }

    if(dp[max_d+1]) cout << "Second" << endl;
    else cout << "First" << endl;
    
    
    return 0;
}