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
    int n, m; cin >> n >> m;
    vector<int> s(m), t(m);
    vector<vector<int>> g(n);
    map<pair<int, int>, int> id;
    rep(i, 0, m){
        cin >> s[i] >> t[i];
        s[i]--, t[i]--;
        g[s[i]].push_back(t[i]);
        id[{s[i], t[i]}] = i;
    }
    vector<vector<int>> path(n); // 1から i への最短パスの1つ
    vector<int> seen(n, -1);
    seen[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nxt: g[q]){
            if(seen[nxt] != -1) continue;
            seen[nxt] = seen[q]+1;
            path[nxt] = path[q];
            path[nxt].push_back(id[{q, nxt}]);
            que.push(nxt);
        }
    }
    vector<int> ans(m, seen[n-1]);
    for(auto e: path[n-1]){
        vector<vector<int>> ng(n);
        rep(i, 0, m){
            if(i == e) continue;
            ng[s[i]].push_back(t[i]);
        }
        vector<int> dist(n, -1);
        dist[0] = 0;
        que.push(0);
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto nxt: ng[q]){
                if(dist[nxt] != -1) continue;
                dist[nxt] = dist[q]+1;
                que.push(nxt);
            }
        }
        ans[e] = dist[n-1];
    }
    rep(i, 0, m){
        cout << ans[i] << endl;
    }

    return 0;
}