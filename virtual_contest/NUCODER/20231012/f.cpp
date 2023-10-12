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

ll ans;
vector<vector<pair<ll, ll>>> g(200005);

vector<ll> dfs(ll pos, ll pre, ll o){
    vector<vector<ll>> ress;
    vector<ll> res(2);
    res[0] = 1;
    for(auto node: g[pos]){
        auto [npos, cost] = node;
        if(npos == pre) continue;
        
        vector<ll> ch = dfs(npos, pos, o);
        if((cost&(1LL<<o)) > 0) swap(ch[0], ch[1]);
        rep(i, 0, 2) res[i] += ch[i];
        ress.push_back(ch);
    }
    ans += res[1]*((1LL<<o)%MOD);
    ans %= MOD;
    for(auto rr: ress){
        ans += (rr[0]*(res[1]-rr[1])+rr[1]*(res[0]-rr[0]))*((1LL<<o)%MOD);
        ans %= MOD;
    }
    return res;
}

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
    
    rep(i, 0, n-1){
        ll u, v, w; cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    
    ll sum = 0;
    rep(i, 0, 60){
        ans = 0;
        auto _ = dfs(0, -1, i);
        sum += ans;
        sum %= MOD;
    }

    cout << (sum*power(2, MOD-2))%MOD << endl;
    
    return 0;
}