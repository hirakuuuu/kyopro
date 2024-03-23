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
// div3_496

int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n);
    vector<int> u(m), v(m);
    rep(i, 0, m){
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    queue<int> que;
    que.push(0);
    vector<int> dist(n, -1);
    dist[0] = 0;
    while(!que.empty()){
        int q = que.front(); que.pop(); 
        for(auto nq: g[q]){
            if(dist[nq] != -1) continue;
            dist[nq] = dist[q]+1;
            que.push(nq);
        }
    }
    vector<vector<int>> ng(n);
    vector<int> id(n);
    set<pair<int, int>> s;
    rep(i, 0, m){
        if(dist[u[i]] > dist[v[i]]) swap(u[i], v[i]);
        if(dist[v[i]]-dist[u[i]] == 1){
            ng[v[i]].push_back(i);
        }
    }
    set<string> ans;
    string tmp;
    rep(i, 0, m) tmp += '0'; 
    auto dfs = [&](auto self, int pos) -> void {
        for(auto edge_id: ng[pos]){
            tmp[edge_id] = '1';
            if(pos == n-1 && ans.size() < k) ans.insert(tmp);
            else if(ans.size() < k) self(self, pos+1);
            tmp[edge_id] = '0';
        }
    };
    dfs(dfs, 1);
    cout << ans.size() << endl;
    for(auto aa: ans){
        cout << aa << endl;
    }

    return 0;
}