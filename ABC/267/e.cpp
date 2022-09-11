#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc267/tasks/abc267_e



int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n), cost(n);
    vector<set<ll>> g(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m){
        ll u, v; cin >> u >> v;
        g[u-1].insert(v-1);
        g[v-1].insert(u-1);
        cost[u-1] += a[v-1];
        cost[v-1] += a[u-1];
    }


    multiset<vector<ll>> node;
    rep(i, 0, n){
        node.insert({cost[i], -a[i], i});
    }

    ll ans = 0;

    rep(i, 0, n){
        auto itr = node.begin();
        vector<ll> now_node = *itr;
        node.erase(itr);

        ans = max(ans, now_node[0]);

        ll id = now_node[2];

        for(auto nx: g[id]){
            g[nx].erase(id);
            node.erase({cost[nx], -a[nx], nx});
            cost[nx] -= a[id];
            node.insert({cost[nx], -a[nx], nx});
        }
    }

    cout << ans << endl;

    
    return 0;
}