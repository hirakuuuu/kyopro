#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
i -> P_i ではなく, P_i -> P_{P_i} なので, 有向グラフ上を 2^k 回移動した先を求めないといけない
なので、ダブリングできない
単純に有向グラフ上のサイクルを考えて, 2^k 回移動した先が何かを考える問題
*/


ll power(ll a, ll b, ll m){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}


int main(){
    ll n, k; cin >> n >> k;
    vector<ll> p(n);
    rep(i, 0, n){
        cin >> p[i];
        p[i]--;
    }
    vector<int> to(n);
    rep(i, 0, n) to[i] = p[i];

    vector<vector<int>> cycle;
    vector<int> seen(n);
    rep(i, 0, n){
        if(seen[i]) continue;
        cycle.push_back({});
        int v = i;
        while(!seen[v]){
            seen[v] = true;
            cycle.back().push_back(v);
            v = to[v];
        }
    }

    vector<int> ans(n);
    for(auto c: cycle){
        int m = (int)c.size();
        int mv = power(2, k, m);
        rep(i, 0, m){
            ans[c[i]] = c[(i+mv)%m];
        }
    }
    rep(i, 0, n){
        cout << ans[i]+1 << ' ';
    }
    cout << endl;
    
    return 0;
}