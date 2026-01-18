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

const int vmax = 10000005; // ここは問題ごとに考慮が必要
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
    int n, a, b; cin >> n >> a >> b;
    int q; cin >> q;
    mint m2 = mint(2);
    mint m3 = mint(3);
    mint m4 = mint(4);

    vector<mint> cnt1(n+1);
    cnt1[b-1] = 1;
    rep(i, b, n+1){
        cnt1[i] = cnt1[i-1]*2+choose(i-1, b-2);
    }
    vector<mint> cnt2(n+1);
    cnt2[n-b] = 1;
    rep(i, n-b+1, n+1){
        cnt2[i] = cnt2[i-1]*2+choose(i-1, n-b-1);
    }
    vector<mint> cnt3(n+1);
    cnt3[a-1] = 1;
    rep(i, a, n+1){
        cnt3[i] = cnt3[i-1]*2+choose(i-1, a-2);
    }
    vector<mint> cnt4(n+1);
    cnt4[n-a] = 1;
    rep(i, n-a+1, n+1){
        cnt4[i] = cnt4[i-1]*2+choose(i-1, n-a-1);
    }

    while(q--){
        int k; cin >> k;
        mint ans = 0;
        if(k == 1){
            ans = choose(n-1, a-1)*choose(n-1, b-1);
        }else{
            if(b != 1 && b != n){
                ans += choose(n-k, a-1)*(m2.pow(n-k)-cnt1[n-k]-cnt2[n-k])*2*m4.pow(k-2);
                ans += choose(n-k, n-a)*(m2.pow(n-k)-cnt1[n-k]-cnt2[n-k])*2*m4.pow(k-2);
            }
            // cout << ans.val() << endl;
            if(a != 1 && a != n){
                ans += choose(n-k, b-1)*(m2.pow(n-k)-cnt3[n-k]-cnt4[n-k])*2*m4.pow(k-2);
                ans += choose(n-k, n-b)*(m2.pow(n-k)-cnt3[n-k]-cnt4[n-k])*2*m4.pow(k-2);
            }
            // cout << ans.val() << endl;
            ans += choose(n-k, a-1)*choose(n-k, b-1)*3*m4.pow(k-2);
            ans += choose(n-k, n-a)*choose(n-k, b-1)*3*m4.pow(k-2);
            ans += choose(n-k, a-1)*choose(n-k, n-b)*3*m4.pow(k-2);
            ans += choose(n-k, n-a)*choose(n-k, n-b)*3*m4.pow(k-2);            
        }
        cout << ans.val() << endl;
    }
    return 0;
}