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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

const int vmax = 2005; // ここは問題ごとに考慮が必要
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


/*
ナイーブなDPを考えると O(n^3). 
i 人のグループが最大でも n/i グループしか作れないことを考えると, 調和級数的に O(n^2\log{n}) に落ちることが分かる
*/

int main(){
    initfact();
    int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    vector<mint> dp(n+1);
    dp[0] = 1;

    auto f = [&](int n_, int k, int p) -> mint {
        assert(n_-p*k >= 0);
        return fact[n_]*finv[n_-p*k]*finv[k].pow(p)*finv[p];
    };

    rep(i, a, b+1){
        vector<mint> dp_ = dp;
        rep(j, 0, n+1){
            rep(k, c, d+1){
                if(j+i*k > n) break;
                dp[j+i*k] += dp_[j]*f(n-j, i, k);
            }
        }
    }
    cout << dp[n].val() << endl;
    
    return 0;
}