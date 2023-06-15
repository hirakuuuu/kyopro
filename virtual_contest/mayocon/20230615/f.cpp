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


int main(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> g(n+1);
    rep(i, 0, m){
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<ll> dist1(n+1, INF), distn(n+1, INF);
    queue<ll> que;
    que.push(1);
    dist1[1] = 0;
    while(!que.empty()){
        ll q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(dist1[nq] < INF) continue;
            dist1[nq] = dist1[q]+1;
            que.push(nq);
        }
    }
    que.push(n);
    distn[n] = 0;
    while(!que.empty()){
        ll q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(distn[nq] < INF) continue;
            distn[nq] = distn[q]+1;
            que.push(nq);
        }
    }

    rep(i, 1, n+1){
        ll ans = dist1[n];
        if(i != 1 && i != n){
            chmin(ans, min(dist1[0]+distn[i], dist1[i]+distn[0]));
        }else if(i != 1){
            chmin(ans, dist1[0]);
        }else if(i != n){
            chmin(ans, distn[0]);
        }

        if(ans == INF) cout << -1 << ' ';
        else cout << ans << ' ';
    }
    cout << endl;
    
    return 0;
}