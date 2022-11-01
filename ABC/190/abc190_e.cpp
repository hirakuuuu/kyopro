#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc190/tasks/abc190_e

vector<vector<int>> g(100005);
vector<int> seen(100005);

vector<ll> dijk(int s){
    priority_queue<pll, vector<pll>, greater<pll>> que;
    vector<ll> dist(100005, (1LL<<60));
    que.push(make_pair(0, s));
    dist[s] = 0;
    while(!que.empty()){
        pll q = que.top(); que.pop();
        ll d = q.first, u = q.second;
        if(dist[u] < d) continue;
        for(auto nq: g[u]){
            ll v = nq, cost = 1;
            if(dist[v] > d+cost){
                dist[v] = d+cost;
                que.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){
    int n, m; cin >> n >> m;
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int k; cin >> k;
    vector<int> c(k);
    vector<vector<ll>> dist(k);
    rep(i, 0, k){
        cin >> c[i];
        c[i]--;
        dist[i] = dijk(c[i]);
    }

    vector<vector<ll>> dp(1<<k, vector<ll>(k, 1LL<<60));
    vector<int> bit(k);
    rep(i, 0, k) dp[(1<<i)][i] = 1;
    rep(i, 1, 1<<k){
        rep(j, 0, k){
            if((i&(1<<j)) > 0) bit[j] = 1;
            else bit[j] = 0;
        }

        rep(j, 0, k){
            rep(l, 0, k){
                if(bit[j] == 0 and bit[l] == 1){
                    dp[i+(1<<j)][j] = min(dp[i+(1<<j)][j], dp[i][l]+dist[l][c[j]]);
                }
            }
        }
    }

    ll ans = 1LL<<60;
    rep(i, 0, k) ans = min(ans, dp[(1<<k)-1][i]);
    if(ans != (1LL<<60)) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}