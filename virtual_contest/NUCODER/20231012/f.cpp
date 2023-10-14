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


ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<vector<pair<ll, ll>>> g(n);
    rep(i, 0, n-1){
        ll u, v, w; cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    vector<ll> dist(n);
    vector<bool> seen(n);
    dist[0] = 0;
    seen[0] = true;
    queue<ll> que;
    que.push(0);
    while(!que.empty()){
        ll q = que.front(); que.pop();
        for(auto gg: g[q]){
            auto [nq, cost] = gg;
            if(seen[nq]) continue;
            seen[nq] = true;
            dist[nq] = dist[q]^cost;
            que.push(nq);
        }
    }

    ll ans = 0;
    rep(i, 0, 60){
        vector<ll> cnt(2);
        rep(j, 0, n){
            cnt[(dist[j]&(1LL<<i)) > 0]++;
        }
        ans += ((cnt[0]*cnt[1])%MOD)*((1LL<<i)%MOD);
        ans %= MOD;
    }
    cout << ans << endl;
    
    return 0;
}