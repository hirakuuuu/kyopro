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
    int n, m, k; cin >> n >> m >> k;
    vector<vector<vector<int>>> g(n, vector<vector<int>>(2));
    rep(i, 0, m){
        int u, v, a; cin >> u >> v >> a;
        u--, v--;
        g[u][a].push_back(v);
        g[v][a].push_back(u);
    }

    vector<int> s(n);
    rep(i, 0, k){
        int ss; cin >> ss;
        ss--;
        s[ss]++;
    }

    queue<pair<int, int>> que;
    que.push({0, 1});
    vector<vector<int>> dist(n, vector<int>(2, -1));
    dist[0][1] = 0;
    while(!que.empty()){
        auto [q, r] = que.front(); que.pop();
        for(auto nq: g[q][r]){
            if(dist[nq][r] != -1) continue;
            dist[nq][r] = dist[q][r]+1;
            que.push({nq, r});
        }
        if(s[q]){
            for(auto nq: g[q][1-r]){
                if(dist[nq][1-r] != -1) continue;
                dist[nq][1-r] = dist[q][r]+1;
                que.push({nq, 1-r});
            }
        }
    }
    int ans = IINF;
    rep(i, 0, 2){
        if(dist[n-1][i] != -1) chmin(ans, dist[n-1][i]);
    }
    if(ans == IINF) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}