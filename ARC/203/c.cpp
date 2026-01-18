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

const int vmax = 1000005; // ここは問題ごとに考慮が必要
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


    int t; cin >> t;
    while(t--){
        ll h, w, k; cin >> h >> w >> k;
        if(k < h+w-2){
            cout << 0 << endl;
            continue;
        }

        if(k == h+w-2){
            cout << choose(h+w-2, h-1).val() << endl;
        }else if(k == h+w-1){
            mint cnt = (2*h*w-h-w)-(h+w-2);
            cout << (choose(h+w-2, h-1)*cnt).val() << endl;
        }else{
            // k = h+w
            mint cnt = (2*h*w-h-w)-(h+w-2);
            mint ans = choose(h+w-2, h-1)*(cnt*(cnt-1)/2);
            ans -= choose(h+w-4, h-2)*(h+w-3);
            ans += choose(h+w-2, h+1)*(h-1);
            ans += choose(h+w-2, w+1)*(w-1);
            // if(h >= 3) ans += choose(h+w-1, w)*(h-2)*(w-1);
            // ans = choose(h+w-1, h-1)*cnt2;

            // ans -= perm(h+w-3, w-1)*finv[w-2];
            
            cout << ans.val() << endl;
        }


    }
    return 0;
}