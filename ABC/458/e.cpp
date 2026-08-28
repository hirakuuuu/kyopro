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

const int vmax = 3500005; // ここは問題ごとに考慮が必要
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
    vector<int> x(3);
    rep(i, 0, 3) cin >> x[i];

    // int n = x[0]+x[1]+x[2];
    mint ans = 0;
    if(x[0] == x[2]){
        rep(k, 2, x[0]+x[2]+1){
            if(x[1] < k-1) continue;
            if(k%2 == 1){
                // 1, 3, ..., 1, 3, 1
                ans += homogeneous(k/2+1, x[0]-k/2-1)*homogeneous(k/2, x[2]-k/2)*homogeneous(x[0]+x[2]+1, x[1]-(k-1));
                // 3, 1, ..., 3, 1, 3
                ans += homogeneous(k/2, x[0]-k/2)*homogeneous(k/2+1, x[2]-k/2-1)*homogeneous(x[0]+x[2]+1, x[1]-(k-1));
            }else{
                // 1, 3, ..., 1, 3
                ans += homogeneous(k/2, x[0]-k/2)*homogeneous(k/2, x[2]-k/2)*homogeneous(x[0]+x[2]+1, x[1]-(k-1));
                // 3, 1, ..., 3, 1
                ans += homogeneous(k/2, x[0]-k/2)*homogeneous(k/2, x[2]-k/2)*homogeneous(x[0]+x[2]+1, x[1]-(k-1));
            }
        }
    }else{
        rep(k, 2, min(x[0], x[2])*2+2){
            if(x[1] < k-1) continue;
            if(k%2 == 1){
                // 1, 3, ..., 1, 3, 1
                if((k+1)/2 <= x[0]){
                    ans += homogeneous(k/2+1, x[0]-k/2-1)*homogeneous(k/2, x[2]-k/2)*homogeneous(x[0]+x[2]+1, x[1]-(k-1));
                }
                // 3, 1, ..., 3, 1, 3
                if((k+1)/2 <= x[2]){
                    ans += homogeneous(k/2, x[0]-k/2)*homogeneous(k/2+1, x[2]-k/2-1)*homogeneous(x[0]+x[2]+1, x[1]-(k-1));
                }
            }else{
                // 1, 3, ..., 1, 3
                ans += homogeneous(k/2, x[0]-k/2)*homogeneous(k/2, x[2]-k/2)*homogeneous(x[0]+x[2]+1, x[1]-(k-1));
                // cout << homogeneous(k/2, x[0]-k/2).val() << ' ' << homogeneous(k/2, x[2]-k/2).val() << ' ' << homogeneous(x[0]+x[2]+1, x[1]-(k-1)).val() << endl;
                // 3, 1, ..., 3, 1
                ans += homogeneous(k/2, x[0]-k/2)*homogeneous(k/2, x[2]-k/2)*homogeneous(x[0]+x[2]+1, x[1]-(k-1));
            }
            // cout << k << ' ' << ans.val() << endl;

        } 
    }
    cout << ans.val() << endl;

    return 0;
}