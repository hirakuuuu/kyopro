#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(ll i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

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
    
    return 0;
}