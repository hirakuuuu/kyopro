#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

const int vmax = 3000005; // ここは問題ごとに考慮が必要
mint fact[vmax], finv[vmax];
void initfact(){
	fact[0]= 1;
	for(ll i = 1; i < vmax; i++) fact[i] = fact[i-1]*i; // 階乗の計算
	finv[vmax-1] = fact[vmax-1].inv();
	for(ll i = vmax-2; i >=0; i--) finv[i] = finv[i+1]*(i+1); // 階乗の逆元
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


/*
奇数の個数の制限を見逃した
*/

int main(){
    initfact();
    int n, m; cin >> n >> m;

    mint ans = 0;
    // 奇数の個数が m個以下
    rep(i, 0, min(n, m)+1){
        if((3*m-i)%2 == 1) continue;
        ans += choose(n, i)*homogeneous((3*m-i)/2+1, n-1);
    }
    // 最大値が 2m より大きいものを引いていく
    mint tmp = 0, elm = 0;
    rep(i, 0, min(n, m)+1){
        if((m-i)%2 == 1) continue;
        tmp += choose(n, i)*homogeneous((m-i)/2+1, n-1);
        if(i < n) elm += choose(n-1, i)*homogeneous((m-i)/2+1, n-2);
    }
    tmp *= n;
    elm *= n;
    ans -= tmp-elm;
    cout << ans.val() << endl;
    return 0;
}