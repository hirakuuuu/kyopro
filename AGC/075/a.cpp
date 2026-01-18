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
    int n; cin >> n;


    auto check = [&](vector<vector<int>> s) -> pair<mint, mint> {
        vector<mint> cnt(2);
        rep(i, 0, s.size()){
            rep(j, 0, s.size()){
                rep(ii, i, s.size()){
                    rep(jj, j, s.size()){
                        if(i == ii && j == jj) continue;
                        if(s[i][j] == s[ii][jj]){
                            cnt[s[i][j]] += choose((ii-i+jj-j), ii-i);
                        }
                    }
                }
            }
        }
        return {cnt[0], cnt[1]};
    };

    auto [c0, c1] = check({
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
    });
    cout << c0.val() << ' ' << c1.val() << endl;

    // for(int bit = 1; bit < 1<<(n*n); bit += 2){
    //     vector<vector<int>> s(n, vector<int>(n));
    //     rep(j, 0, n*n){
    //         if((bit>>j)&1) s[j/n][j%n] = 1;
    //     }
    //     auto [c0, c1] = check(s);
    //     if(c0 == c1){
    //         rep(i, 0, n){
    //             rep(j, 0, n){
    //                 cout << s[i][j];
    //             }
    //             cout << endl;
    //         }
    //         cout << endl;
    //     }

    // }



    return 0;
}