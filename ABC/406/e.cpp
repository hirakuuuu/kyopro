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

const int vmax = 20005; // ここは問題ごとに考慮が必要
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
    int t; cin >> t;
    vector<vector<mint>> dp(61, vector<mint>(61));
    rep(i, 1, 61){
        rep(j, 0, i+1){
            dp[i][j] += dp[i-1][j];
            if(j > 0) dp[i][j] += dp[i-1][j-1]+choose(i-1, j-1)*(1LL<<(i-1));
        }
    }
    while(t--){
        ll n, k; cin >> n >> k;

        int o = 0;
        ll _n = n;
        while(_n){
            o++;
            _n >>= 1;
        }

        int cnt1 = 0;
        mint ans = 0;
        ll num = 0;
        rrep(i, o-1, 0){
            if((n>>i)&1){
                if(k-cnt1 >= 0) ans += choose(i, k-cnt1)*num+dp[i][k-cnt1];
                cnt1++;
                num += 1LL<<i;
            }
            // cout << i << ' ' << ans.val() << endl;
        }
        if(cnt1 == k) ans += n;
        cout << ans.val() << endl;
    }

    
    return 0;
}