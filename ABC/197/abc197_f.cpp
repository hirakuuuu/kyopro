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
// https://atcoder.jp/contests/abc197/tasks/abc197_f

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    vector<char> c(m);
    vector<vector<int>> g(n*n);
    rep(i, 0, m){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
    }

    rep(i, 0, m){
        rep(j, 0, m){
            if(c[i] == c[j]){
                g[a[i]*n+a[j]].push_back(b[i]*n+b[j]);
                g[b[i]*n+b[j]].push_back(a[i]*n+a[j]);
                g[a[i]*n+b[j]].push_back(b[i]*n+a[j]);
                g[b[i]*n+a[j]].push_back(a[i]*n+b[j]);
            }
        }
    }

    queue<int> que;
    que.push(n-1);
    vector<ll> dist(n*n, 9e18);
    dist[n-1] = 0;
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(dist[nq] != 9e18) continue;
            dist[nq] = dist[q]+2;
            que.push(nq);
        }
    }

    ll ans = 9e18;
    rep(i, 0, n) chmin(ans, dist[i*n+i]);
    rep(i, 0, m) chmin(ans, min(dist[a[i]*n+b[i]], dist[b[i]*n+a[i]])+1);
    if(ans != 9e18) cout << ans << endl;
    else cout << -1 << endl;
    
    return 0;
}