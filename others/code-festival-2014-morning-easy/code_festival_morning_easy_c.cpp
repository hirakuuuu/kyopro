#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/code-festival-2014-morning-easy/tasks/code_festival_morning_easy_c

vector<vector<pll>> g(100005);

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
    int n, m; cin >> n >> m;
    int s, t; cin >> s >> t;
    rep(i, 0, m){
        ll x, y, d; cin >> x >> y >> d;
        g[x].push_back({y, d});
        g[y].push_back({x, d});
    }

    vector<ll> dist_s = dijk(s);
    vector<ll> dist_t = dijk(t);

    rep(i, 1, n+1){
        if(dist_s[i] != (1LL<<60) and dist_s[i] == dist_t[i]){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;


    
    return 0;
}