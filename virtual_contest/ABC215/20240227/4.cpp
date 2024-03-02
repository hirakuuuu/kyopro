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
// 

// 素因数分解
// {素数、指数}で格納
vector<pll> prime_factorization(ll n){
    vector<pll> primes;
    for (ll p = 2; p *p <= n; p++){
        if(n%p != 0) continue;

        ll cnt = 0;
        while(n%p == 0){
            n /= p;
            cnt++;
        }
        primes.push_back({p, cnt});
    }
    if(n != 1) primes.push_back({n, 1});
    return primes;
}

int main(){
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<vector<pll>> primes(n);
    set<ll> p;
    rep(i, 0, n){
        primes[i] = prime_factorization(a[i]);
        for(auto [q, r]: primes[i]){
            p.insert(q);
        }
    }
    vector<ll> s(m+1, 1);
    for(auto pp: p){
        for(int i = pp; i <= m; i += pp) s[i] = 0;
    }
    vector<ll> ans;
    rep(i, 1, m+1){
        if(s[i]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(auto aa: ans){
        cout << aa << endl;
    }




    
    return 0;
}