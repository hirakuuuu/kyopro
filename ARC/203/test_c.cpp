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

const int vmax = 500005; // ここは問題ごとに考慮が必要
mint fact[vmax], finv[vmax];
void initfact(){
	fact[0]= 1;
	for(int i = 1; i < vmax; i++) fact[i] = fact[i-1]*i; // 階乗の計算
	finv[vmax-1] = fact[vmax-1].inv();
	for(int i = vmax-2; i >=0; i--) finv[i] = finv[i+1]*(i+1); // 階乗の逆元
}

mint perm(int n, int k){
	return n-k >= 0?fact[n]*finv[n-k]:0;
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


    for(int h = 2; h <= 10; h++){
        cout << "h=" << h << ": ";
        for(int w = 2; w <= 10; w++){
            mint ans = 0;
            rep(i, 1, h) rep(j, 1, w){
                ans += choose(i+j-2, i-1)*choose(h+w-i-j-2, h-i-1);
            }
            cout << ans.val() << ' ';
        }
        cout << endl;
    }

    for(int h = 2; h <= 10; h++){
        cout << "h=" << h << ": ";
        for(int w = 2; w <= 10; w++){
            cout << (perm(h+w-3, w-1)*finv[w-2]).val() << ' ';
        }
        cout << endl;
    }
    return 0;
}