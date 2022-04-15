#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc192/tasks/abc192_e

vector<ll> dist(100005, -1);
vector<ll> a(100005), b(100005), t(100005), k(100005);
vector<vector<pll>> g(100005);

void dijk(ll s){
    priority_queue<pll> que;
    que.push({0, s});
    while(!que.empty()){
        pll q = que.top(); que.pop();
        q.first *= -1;
        if(dist[q.second] >= 0) continue;
        dist[q.second] = q.first;
        for(auto nq: g[q.second]){
            ll wait = (k[nq.first]-q.first%k[nq.first])%k[nq.first];
            que.push({(q.first+wait+t[nq.first])*(-1), nq.second});
        }
    }
}


int main(){
    ll n, m, x, y; cin >> n >> m >> x >> y;
    rep(i, 0, m) cin >> a[i] >> b[i] >> t[i] >> k[i];
    rep(i, 0, m){
        g[a[i]].push_back({i, b[i]});
        g[b[i]].push_back({i, a[i]});
    }
    dijk(x);
    cout << dist[y] << endl;    
    return 0;
}