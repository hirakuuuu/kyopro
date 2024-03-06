#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(ll i = a; i >= n; i--)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr ll IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<vector<ll>> g(n);
    rep(i, 0, n-1){
        ll u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> med(n);
    multiset<ll> mi, mx;
    auto dfs = [&](auto sfs, ll pos, ll pre)->void{
        mx.insert(a[pos]);
        if(mx.size()-mi.size() == 2){
            ll tmp = *mx.begin();
            mx.erase(mx.find(tmp));
            mi.insert(tmp);
        }else if(mi.size() && mx.size()-mi.size() == 1){
            ll l = *mi.rbegin(), r = *mx.begin();
            if(l > r){
                mi.erase(mi.find(l));
                mi.insert(r);
                mx.erase(mx.find(r));
                mx.insert(l);
            }
        }
        if(pos != 0 && g[pos].size() == 1){
            if(mx.size()-mi.size() == 1) med[pos] = *mx.begin();
            else med[pos] = (*mi.rbegin()+*mx.begin())/2;
        }
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            sfs(sfs, nxt, pos);
        }
        if(mi.find(a[pos]) != mi.end()) mi.erase(mi.find(a[pos]));
        else mx.erase(mx.find(a[pos]));
        if(mx.size()-mi.size() == 2){
            ll tmp = *mx.begin();
            mx.erase(mx.find(tmp));
            mi.insert(tmp);
        }else if(mi.size() > mx.size()){
            ll tmp = *mi.rbegin();
            mi.erase(mi.find(tmp));
            mx.insert(tmp);
        }


    };
    dfs(dfs, 0, -1);

    vector<ll> max_med(n), min_med(n, IINF);
    auto dfs_dp = [&](auto sfs, ll pos, ll pre, ll d)->void{
        if(pos != 0 && g[pos].size() == 1){
            max_med[pos] = min_med[pos] = med[pos];
        }
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            sfs(sfs, nxt, pos, d);
            chmax(max_med[pos], min_med[nxt]);
            chmin(min_med[pos], max_med[nxt]);
        }
    };
    dfs_dp(dfs_dp, 0, -1, 0);
    cout << max_med[0] << endl;

    
    return 0;
}