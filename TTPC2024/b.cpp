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

const int vmax = 2000005; // ここは問題ごとに考慮が必要
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
    vector<int> s(n);
    rep(i, 0, n) cin >> s[i];
    
    // 末尾以外に 1 があるとだめ
    rep(i, 0, n-1){
        if(s[i] == 1){
            cout << 0 << endl;
            return 0;
        }
    }

    if(s == vector<int>(1, 1)){
        cout << 1 << endl;
        return 0;
    }
    if(s.back() == 1) s.pop_back();
    n = s.size();

    // 最後に 3 が出てくる位置
    int p = -1;
    rep(i, 0, n){
        if(s[i] == 3){
            chmax(p, i);
        }
    }

    vector<int> b(n);
    rep(i, 0, n){
        if(p < i) b[i] = s[i];
        else b[i] = s[i]-1;
    }

    mint ans = 1;
    // int cnt = 0;
    for(int l = -1; l < p; ){
        int r = l+1;
        while(r < n && b[r] != 1) r++;
        if(r == n){
            if(p-l == 1) ans *= n-p+1;
            else catalan(r-l);
        }else{
            ans *= catalan(r-l);
        }
        l = r;
    }
    cout << ans.val() << endl;
    mint tmp = ans;

    rep(k, p+2, n+1) ans += tmp*catalan(n-p);
    cout << ans.val() << endl;


    return 0;
}