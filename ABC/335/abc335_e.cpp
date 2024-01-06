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
// https://atcoder.jp/contests/abc335/tasks/abc335_e

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({a[0], 0});
    vector<int> kind(n);
    kind[0] = 1;
    while(!que.empty()){
        auto [p, v] = que.top(); que.pop();
        for(auto nv: g[v]){
            if(a[nv] < a[v]) continue;
            if(kind[nv] < kind[v]+(a[nv] != a[v])){
                kind[nv] = kind[v]+(a[nv] != a[v]);
                que.push({a[nv], nv});
            }
        }
    }
    cout << kind[n-1] << endl;
    return 0;
}