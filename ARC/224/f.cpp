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

const int vmax = 250005; // ここは問題ごとに考慮が必要
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    initfact();
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<ll> a(n);
        rep(i, 0, n) cin >> a[i];

        mint ans = 0;

        // 最大値 M を求める
        ll M = 0;
        int mi = n;
        vector<int> bit;
        rrep(i, 59, 0){
            // bit i を立てられるか
            if(M>>i&1) continue;
            int r = -1;
            rep(j, 0, n){
                if(a[j]>>i&1) r = j;
            }
            if(r != -1 && n-r <= k){
                if(mi > r){
                    mi = r;
                    bit.clear();
                }else if(mi == r){
                    bit.push_back(i);
                }
                rep(j, r, n){
                    M |= a[j];
                }
            }
        }
        cout << M << endl;
        cout << mi << endl;
        // mi より後ろは全部 OR
        ans += choose(mi, k-(n-mi));
        k -= n-mi-1;
        

        while(mi != n){
            int _mi = mi;
            vector<int> _bit;
            M = 0;
            for(auto i: bit){
                // bit i を立てられるか
                if(M>>i&1) continue;
                int r = -1;
                rep(j, 0, mi){
                    if(a[j]>>i&1) r = j;
                }
                if(r != -1 && mi-r <= k){
                    if(_mi > r){
                        _mi = r;
                        _bit.clear();
                    }else if(_mi == r){
                        _bit.push_back(i);
                    }
                    rep(j, r, mi){
                        M |= a[j];
                    }
                }
            }

            ans += choose(_mi, k-(mi-_mi));
            k -= mi-_mi-1;
            mi = _mi;
        }
        cout << ans.val() << endl;
    }
    
    return 0;
}