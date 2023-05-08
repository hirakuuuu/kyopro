#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_d

vector<vector<pll>> g_a(100005), g_b(100005);

// sを始点とする各頂点への距離の最小値を格納した配列を返す
vector<ll> dijk(ll s, vector<vector<pll>> &g){
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
    ll n, m, s, t; cin >> n >> m >> s >> t;
    rep(i, 0, m){
        ll u, v, a, b; cin >> u >> v >> a >> b;
        g_a[u].push_back({v, a});
        g_a[v].push_back({u, a});
        g_b[u].push_back({v, b});
        g_b[v].push_back({u, b});
    }

    ll rest = 1;
    rep(i, 0, 15) rest *= 10;

    vector<ll> dist_s_a = dijk(s, g_a), dist_t_b = dijk(t, g_b);
    vector<ll> cost(n+1);
    rep(i, 1, n+1) cost[i] = dist_s_a[i]+dist_t_b[i];

    priority_queue<pll> que;
    rep(i, 1, n+1) que.push({rest-cost[i], i});

    ll year = 0;
    while(year < n){
        pll q = que.top();
        if(q.second <= year){
            que.pop();
            continue;
        }
        cout << q.first << endl;
        year++;
    }
    
    return 0;
}