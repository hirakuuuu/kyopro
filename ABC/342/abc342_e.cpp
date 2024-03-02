#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll, ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc342/tasks/abc342_e

int main(){
    int n, m; cin >> n >> m;
    vector<vector<tll>> g(n);
    rep(i, 0, m){
        ll l, d, k, c, a, b; cin >> l >> d >> k >> c >> a >> b;
        a--, b--;
        g[b].push_back({a, l, d, k, c});
    }
    priority_queue<pair<ll, ll>> que;
    que.push({INF, n-1});
    vector<ll> dist(n, -1);
    dist[n-1] = INF;
    while(!que.empty()){
        auto [t, p] = que.top(); que.pop();
        if(dist[p] > t) continue;
        for(auto [nxt, l, d, k, c]: g[p]){
            if(t < l+c) continue;
            ll tmp = min(k, (t-c-l)/d+1);
            if(dist[nxt] < l+(tmp-1)*d){
                dist[nxt] = l+(tmp-1)*d;
                que.push({l+(tmp-1)*d, nxt});
                // cout << l+(tmp-1)*d << ' ' << nxt << endl;
            }
        }
    }
    rep(i, 0, n-1){
        if(dist[i] == -1) cout << "Unreachable" << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}