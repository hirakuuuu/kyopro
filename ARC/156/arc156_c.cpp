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
// https://atcoder.jp/contests/arc156/tasks/arc156_c

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    queue<int> que;
    rep(i, 0, n){
        if(deg[i] == 1){
            que.push(i);
        }
    }
    vector<int> p(n);
    while(que.size() >= 2){
        int u = que.front(); que.pop();
        int v = que.front(); que.pop();
        p[u] = v;
        p[v] = u;
        for(auto nxt: g[u]){
            if(deg[nxt] >= 2){
                deg[nxt]--;
                if(deg[nxt] == 1) que.push(nxt);
            }
        }
        for(auto nxt: g[v]){
            if(deg[nxt] >= 2){
                deg[nxt]--;
                if(deg[nxt] == 1) que.push(nxt);
            }
        }
    }
    if(que.size() == 1){
        int q = que.front(); que.pop();
        p[q] = q;
    }
    rep(i, 0, n){
        cout << p[i]+1 << ' ';
    }
    cout << endl;






    
    return 0;
}