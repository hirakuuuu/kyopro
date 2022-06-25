#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc257/tasks/abc257_f
vector<vector<int>> g(300005);
vector<ll> dist1(300005, (1LL<<50)), distn(300005, (1LL<<50));

void bfs(ll s, vector<ll> &dist){
    queue<pll> que;
    que.push({s, 0LL});
    while(!que.empty()){
        pii q = que.front(); que.pop();
        if(dist[q.first] <= q.second) continue;
        dist[q.first] = q.second;
        for(auto nq: g[q.first]){
            if(dist[nq] > q.second+1) que.push({nq, q.second+1});
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<ll> u(m), v(m), have(n+1);
    rep(i, 0, m){
        cin >> u[i] >> v[i];
        if(u[i] == 0) have[v[i]] = 1;
        else{
            g[u[i]].push_back(v[i]);
            g[v[i]].push_back(u[i]);
        }
    }

    bfs(1, dist1);
    bfs(n, distn);


    ll min_1 = (1LL<<50), min_n = (1LL<<50);
    rep(i, 1, n+1){
        if(have[i]){
            min_1 = min(min_1, dist1[i]);
            min_n = min(min_n, distn[i]);
        }
    }

    rep(i, 1, n+1){
        ll ans = (1LL<<50);
        ans = min(ans, dist1[n]);
        ans = min(ans, min_1+1+distn[i]);
        ans = min(min_n+1+dist1[i], ans);
        ans = min(min_1+2+min_n, ans);
        if(ans < (1LL<<50)) cout << ans << " ";
        else cout << -1 << " ";
    }
    cout << endl;

    return 0;
}