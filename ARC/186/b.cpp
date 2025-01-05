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


const int vmax = 350005; // ここは問題ごとに考慮が必要
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
a[i] <= i という辺を張って根付き木にする
条件を整理すると，各部分木について，根とその子に関する不等式だけが必要十分とわかる
*/

int main(){
    initfact();
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    vector<vector<int>> g(n+1);
    vector<int> sz(n+1);
    rrep(i, n, 1) g[a[i]].push_back(i);
    rrep(i, n, 0){
        for(auto c: g[i]){
            sz[i] += sz[c];
        }
        sz[i]++;
    }

    mint ans = 1;
    rrep(i, n, 0){
        int rem = sz[i]-1;
        for(auto c: g[i]){
            // その時点での最小値を c に割り当てる
            ans *= choose(rem-1, sz[c]-1);
            rem -= sz[c];
        }
    }
    cout << ans.val() << endl;

    
    return 0;
}