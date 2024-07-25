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


int main(){
    initfact();
    int n, m, k; cin >> n >> m >> k;
    vector<int> a, cnt(m+1);
    rep(i, 0, n){
        int a_; cin >> a_;
        cnt[a_]++;
        if(a_ > 0) a.push_back(a_);
    }
    sort(a.begin(), a.end());
    int zeros = cnt[0];
    if(zeros == 0){
        cout << a[k-1] << endl;
        return 0;
    }
    mint e = 0, minv = mint(m).inv();
    int l = 0, r = n-zeros;
    rep(i, 1, m+1){
        r -= cnt[i];
        if(l <= k-1 && r <= n-k){
            mint z = 0;
            // l >= k となる確率
            rep(j, max(k-l, 0), zeros+1){
                z += choose(zeros, j)*((minv*(i-1)).pow(j))*((minv*(m-i+1)).pow(zeros-j));
            }
            // r >= n-k+1 となる確率
            rep(j, n-k+1-r, zeros+1){
                z += choose(zeros, j)*((minv*(m-i)).pow(j))*((minv*(i)).pow(zeros-j));
            }
            e += (-z+1)*i;
        }
        l += cnt[i];
    }
    cout << e.val() << endl;


    
    return 0;
}