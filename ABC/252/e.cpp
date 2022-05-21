#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc252/tasks/abc252_e

vector<vector<vector<ll>>> g(200005);
vector<ll> dist(200005, -1);
vector<ll> ans;

void dijk(int s){
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> que;
    que.push({0, s, -1});
    while(!que.empty()){
        vector<ll> q = que.top(); que.pop();
        if(dist[q[1]] >= 0) continue;
        dist[q[1]] = q[0];
        if(q[2] > 0) ans.push_back(q[2]);
        for(auto nq: g[q[1]]){
            if(dist[nq[1]] >= 0) continue;
            que.push({q[0]+nq[0], nq[1], nq[2]});
        }
    }
}

int main(){
    ll n, m; cin >> n >> m;
    rep(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        g[a].push_back({c, b, i+1});
        g[b].push_back({c, a, i+1});
    }
    dijk(1);
    rep(i, 0, n-1){
        cout << ans[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}