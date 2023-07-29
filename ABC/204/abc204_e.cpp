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
// https://atcoder.jp/contests/abc204/tasks/abc204_e

vector<vector<tuple<ll, ll, ll>>> g;

ll meguru(ll d, ll t){
    ll l = t, r = 9e18;
    while(r-l > 0){
        ll m = (l+r)/2;
        if((double)d/(m+1) - (double)d/(m+2) >= 1) l = m+1;
        else r = m;
    }
    return l;
}

vector<ll> dijk(int s, int n){
    priority_queue<pll, vector<pll>, greater<pll>> que;
    vector<ll> dist(n, (1LL<<60));
    que.push(make_pair(0, s));
    dist[s] = 0;
    while(!que.empty()){
        pll q = que.top(); que.pop();
        auto [d, u] = q;
        if(dist[u] < d) continue;
        for(auto road: g[u]){
            auto [next, cost, w] = road;
            ll best_t = meguru(w, d);
            if(dist[next] > best_t+cost+w/(best_t+1)){
                dist[next] = best_t+cost+w/(best_t+1);
                que.push({dist[next], next});
            }
        }
    }
    return dist;
}


int main(){
    int n, m; cin >> n >> m;
    g.resize(n);
    rep(i, 0, m){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        a--, b--;
        g[a].push_back({b, c, d});
        g[b].push_back({a, c, d});
    }

    vector<ll> ans = dijk(0, n);

    if(ans[n-1] == (1LL<<60)) cout << -1 << endl;
    else cout << ans[n-1] << endl;



    return 0;
}