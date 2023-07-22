#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc201/tasks/abc201_e


int main(){
    int n; cin >> n;
    vector<vector<pair<ll, ll>>> g(n);
    rep(i, 0, n-1){
        ll u, v, w; cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    queue<pair<ll, ll>> que;
    que.push({0, 0});
    vector<ll> dist(n, 0);
    vector<bool> seen(n);
    seen[0] = true;

    while(!que.empty()){
        pair<ll, ll> q = que.front(); que.pop();
        for(auto nq: g[q.first]){
            if(seen[nq.first]) continue;
            seen[nq.first] = true;
            dist[nq.first] = q.second^nq.second;
            que.push({nq.first, dist[nq.first]});
        }
    }

    ll ans = 0;
    rep(i, 0, 60){
        vector<ll> c(2);
        rep(j, 0, n){
            c[(dist[j]&(1LL<<i)) > 0]++;
        }
        ans += ((1LL<<i)%MOD)*(c[0]*c[1]%MOD);
        ans %= MOD;
    }


    cout << ans << endl;


    return 0;
}