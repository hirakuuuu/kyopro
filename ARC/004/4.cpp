#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 素因数分解
// {素数、指数}で格納
vector<pair<ll, ll>> prime_factorization(ll n){
    vector<pair<ll, ll>> primes;
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

const int vmax = 200005; // ここは問題ごとに考慮が必要
mint fact[vmax], finv[vmax];
void initfact(){
	fact[0]= 1;
	for(int i = 1; i < vmax; i++) fact[i] = fact[i-1]*i; // 階乗の計算
	finv[vmax-1] = fact[vmax-1].inv();
	for(int i = vmax-2; i >=0; i--) finv[i] = finv[i+1]*(i+1); // 階乗の逆元
}
// nCk
mint choose(int n,int k){
    if(n < 0 || k < 0 || n < k) return 0;
    if(n == 0 && k == 0) return 1;
	return fact[n]*finv[n-k]*finv[k];
}
// (a+b)!/(a!b!)
mint binom(int a,int b){
	return 0<=a&&0<=b?fact[a+b]*finv[a]*finv[b]:0;
}
// カタラン数（括弧列とか）
mint catalan(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}
// 重複組み合わせ
mint homogeneous(int n, int k){
    return choose(n+k-1, k);
}

int main(){
    initfact();
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> pn = prime_factorization(abs(n));
    // プラス、マイナスの割り当て
    mint pm = 0;
    rep(i, 0, m+1){
        if(n > 0){
            if(i%2 == 0) pm += choose(m, i);
        }else{
            if(i%2 == 1) pm += choose(m, i);
        }
    }
    
    mint ans = 1;
    for(auto [p, e]: pn) ans *= homogeneous(m, e);
    cout << (pm*ans).val() << endl;
    
    return 0;
}