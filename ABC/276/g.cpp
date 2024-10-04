#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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

const int vmax = 15000005; // ここは問題ごとに考慮が必要
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

/*
\sum{a_i} \le S を満たす非負整数列 {a_i} の個数 (|a| = n): \binom{S+n}{n}
- S 個のボールを n 個の仕切りで分けるとき, 前 n-1 個の区間を対応させる
- 最後の仕切りによる区間は、無視することで, S 以下の場合が全て考えられる

今回の場合, b_1 = a_1, b_i = a_i-a_{i-1} とすると、
3で割った余りを x_i, 3で割ったときの商を y_i とする. 
x_2 ~ x_n は 1 or 2
よって、x_1 と x_2 ~ x_n の中の 1 の個数を決め打ったとき、それに対応する{y_i}の個数が分かればよい
{y_i} の個数は上の考え方で S = (m-\sum{x})/3 としてあげれば求まる. 
*/

int main(){
    initfact();
    int n, m; cin >> n >> m;
    mint ans = 0;
    rep(r0, 0, 3){
        rep(r2, 0, n){
            int r1 = n-1-r2;
            int sum_r = r0+r1+2*r2;
            if(m-sum_r < 0) break;
            ans += choose(n-1, r1)*choose((m-sum_r)/3+n, n);
            // cout << r0 << ' ' << r2 << ' ' << ans.val() << endl;
        }
    }
    cout << ans.val() << endl;


    return 0;
}