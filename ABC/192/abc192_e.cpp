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
// https://atcoder.jp/contests/abc192/tasks/abc192_e



int main(){
    int n, m, x, y; cin >> n >> m >> x >> y;
    x--, y--;
    vector<vector<tuple<ll, ll, ll>>> g(n);
    rep(i, 0, m){
        int a, b, t, k; cin >> a >> b >> t >> k;
        a--, b--;
        g[a].push_back({b, t, k});
        g[b].push_back({a, t, k});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    que.push({0, x});
    vector<ll> dist(n, 9e18);
    dist[x] = 0;
    while(!que.empty()){
        auto [d, q] = que.top(); que.pop();
        if(dist[q] < d) continue;
        for(auto [nq, t, k]: g[q]){
            ll dep = d+(k-d%k)%k;
            if(dist[nq] > dep+t){
                dist[nq] = dep+t;
                que.push({dist[nq], nq});
            }
        }
    }
    if(dist[y] == 9e18) cout << -1 << endl;
    else cout << dist[y] << endl;

    return 0;
}