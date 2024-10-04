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
constexpr ll INF = 9e18;

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

// nPk
mint permutation(int n,int k){
    if(n < 0 || k < 0 || n < k) return 0;
    if(n == 0 && k == 0) return 1;
	return fact[n]*finv[n-k];
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
    int n, m, b, w; cin >> n >> m >> b >> w;

    vector<vector<mint>> dpw(n+1, vector<mint>(m+1));
    vector<vector<mint>> dpb(n+1, vector<mint>(m+1));
    rep(i, 1, n+1){
        rep(j, 1, m+1){
            dpw[i][j] = choose(i*j, w);
            rep(k, 1, i+1) rep(l, 1, j+1){
                if(k == i && l == j) continue;
                dpw[i][j] -= choose(i, k)*choose(j, l)*dpw[k][l];
            }
            dpb[i][j] = choose(i*j, b);
            rep(k, 1, i+1) rep(l, 1, j+1){
                if(k == i && l == j) continue;
                dpb[i][j] -= choose(i, k)*choose(j, l)*dpb[k][l];
            }
        }
    }

    mint ans = 0;
    rep(bi, 1, n) rep(wi, 1, n){
        if(bi+wi > n) break;
        rep(bj, 1, m) rep(wj, 1, m){
            if(bj+wj > m) break;
            ans += choose(n, bi)*choose(n-bi, wi)*choose(m, bj)*choose(m-bj, wj)*dpb[bi][bj]*dpw[wi][wj];
        }
    }
    cout << ans.val() << endl;
    
    return 0;
}