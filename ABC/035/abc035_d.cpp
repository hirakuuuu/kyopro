#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc035/tasks/abc035_d

vector<ll> a(100005);
vector<vector<pll>> g1(100005);
vector<vector<pll>> g2(100005);

vector<ll> dijk(int s, vector<vector<pll>> &g){
    priority_queue<pll, vector<pll>, greater<pll>> que;
    vector<ll> dist(100005, (1LL<<60));
    que.push(make_pair(0, s));
    dist[s] = 0;
    while(!que.empty()){
        pll q = que.top(); que.pop();
        ll d = q.first, u = q.second;
        if(dist[u] < d) continue;
        for(auto nq: g[u]){
            ll v = nq.first, cost = nq.second;
            if(dist[v] > d+cost){
                dist[v] = d+cost;
                que.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){
    ll n, m, t; cin >> n >> m >> t;
    rep(i, 0, n) cin >> a[i+1];
    rep(i, 0, m){
        int A, B, C; cin >> A >> B >> C;
        g1[A].push_back({B, C});
        g2[B].push_back({A, C});
    }

    vector<ll> dist = dijk(1, g1);
    vector<ll> re_dist = dijk(1, g2); 

    ll ans = 0;

    rep(i, 1, n+1){
        ll total = dist[i]+re_dist[i];
        if(total <= t){
            ans = max(ans, (t-total)*a[i]);
        }
    }

    cout << ans << endl;

    
    return 0;
}