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


const int vmax = 200005; // ここは問題ごとに考慮が必要
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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    
    map<tuple<int, int, int>, mint> dp;
    dp[{0, 0, 0}] = 1;
    rep(i, 0, n){
        map<tuple<int, int, int>, mint> ndp;
        for(auto [key, val]: dp){
            if(val == 0) continue;
            auto [v1, v2, v3] = key;
            assert(v1 >= v2 && v2 >= v3);
            if(v1 == 0){
                // v1 = v2 = v3 = 0
                // ndp[{1, 1, 1}] += val*choose(a[i], 3);
                ndp[{1, 1, 0}] += val*choose(a[i], 2);
                ndp[{1, 0, 0}] += val*choose(a[i], 1);
                ndp[{0, 0, 0}] += val;

                // 一気に3枚使うパターンを数える
                ndp[{3, 0, 0}] += val*choose(a[i], 3);
                ndp[{3, 1, 0}] += val*choose(a[i], 4);
                ndp[{3, 1, 1}] += val*choose(a[i], 5);
                ndp[{3, 3, 0}] += val*choose(a[i], 6);
                ndp[{3, 3, 1}] += val*choose(a[i], 7);
                ndp[{3, 3, 3}] += val*choose(a[i], 9);

            }else if(v2 == 0){
                // v2 = v3 = 0
                if(v1 != 3){
                    ndp[{v1+1, 1, 1}] += val*choose(a[i], 3);
                    ndp[{v1+1, 1, 0}] += val*choose(a[i], 2);
                    ndp[{v1+1, 0, 0}] += val*choose(a[i], 1);

                    // 一気に3枚使うパターンを数える
                    ndp[{3, v1+1, 0}] += val*choose(a[i], 4);
                    ndp[{3, v1+1, 1}] += val*choose(a[i], 5);
                    ndp[{3, 3, v1+1}] += val*choose(a[i], 7);
                }else{
                    ndp[{v1, 1, 1}] += val*choose(a[i], 2);
                    ndp[{v1, 1, 0}] += val*choose(a[i], 1);
                    ndp[{v1, 0, 0}] += val;

                    // 一気に3枚使うパターンを数える
                    ndp[{3, v1, 0}] += val*choose(a[i], 3);
                    ndp[{3, v1, 1}] += val*choose(a[i], 4);
                    ndp[{3, 3, v1}] += val*choose(a[i], 6);
                }
            }else if(v3 == 0){
                // v3 = 0
                if(v1 < 3){
                    ndp[{v1+1, v2+1, 1}] += val*choose(a[i], 3);
                    ndp[{v1+1, v2+1, 0}] += val*choose(a[i], 2);

                    // 一気に3枚使うパターンを数える
                    ndp[{3, v1+1, v2+1}] += val*choose(a[i], 5);
                }else if(v2 < 3){
                    ndp[{v1, v2+1, 1}] += val*choose(a[i], 2);
                    ndp[{v1, v2+1, 0}] += val*choose(a[i], 1);

                    // 一気に3枚使うパターンを数える
                    ndp[{3, v1, v2+1}] += val*choose(a[i], 4);
                }else{
                    ndp[{v1, v2, 1}] += val*choose(a[i], 1);
                    ndp[{v1, v2, 0}] += val;

                    // 一気に3枚使うパターンを数える
                    ndp[{3, v1, v2}] += val*choose(a[i], 3);
                }
            }else{
                // v3 > 0
                if(v1 < 3){
                    ndp[{v1+1, v2+1, v3+1}] += val*choose(a[i], 3);
                }else if(v2 < 3){
                    ndp[{v1, v2+1, v3+1}] += val*choose(a[i], 2);
                }else if(v3 < 3){
                    ndp[{v1, v2, v3+1}] += val*choose(a[i], 1);
                }else{
                    ndp[{v1, v2, v3}] += val;
                }
            }
        }
        swap(dp, ndp);
        // cout << "####################################################" << endl;
        // for(auto [key, val]: dp){
        //     if(val == 0) continue;
        //     auto [v1, v2, v3] = key;
        //     cout << v1 << ' ' << v2 << ' ' << v3 << ": ";
        //     cout << val.val() << endl;
        // }
    }

    cout << dp[{3, 3, 3}].val() << endl;
    
    return 0;
}