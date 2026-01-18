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
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> cnt(m+1);
    rep(i, 0, n){
        cin >> a[i];
        cnt[a[i]]++;
    }

    int cnt_l = 0;
    mint pr_l = 0;
    mint ans = 0;
    rep(i, 1, m+1){
        if(cnt_l >= k) break;
        cnt_l += cnt[i];
        // k 番目が i 以下となる確率を求める
        mint tmp = 0;
        rep(j, max(0, k-cnt_l), cnt[0]+1){
            // cout << j << ' ' << cnt[0]-j << endl;
            tmp += choose(cnt[0], j)*mint(i).pow(j)*mint(m-i).pow(cnt[0]-j);
        }
        mint pr = tmp/mint(m).pow(cnt[0]);
        // cout << i << ' ' << (pr*mint(m).pow(cnt[0])).val() << ' ' << (pr_l*mint(m).pow(cnt[0])).val()  << endl;

        ans += (pr-pr_l)*i;
        pr_l = pr;
    }
    cout << ans.val() << endl;



    return 0;
}