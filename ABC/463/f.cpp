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

const int vmax = 1000005; // ここは問題ごとに考慮が必要
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
    vector<int> a(2*n);
    rep(i, 0, 2*n){
        cin >> a[i];
    }
    int mx = *max_element(a.begin(), a.end());
    vector<vector<int>> cnt(3, vector<int>(3));
    rep(i, 0, n){
        int l = 2*i, r = 2*i+1;
        int pl = -1, pr = -1;
        if(a[l] <= mx-2) pl = 0;
        else if(a[l] == mx-1) pl = 1;
        else pl = 2;
        if(a[r] <= mx-2) pr = 0;
        else if(a[r] == mx-1) pr = 1;
        else pr = 2;
        
        cnt[pl][pr]++;
    }
    rep(i, 0, 3){
        rep(j, 0, 3){
            if(i > j) cnt[j][i] += cnt[i][j];
        }
    }

    vector<mint> ans(2*n);
    map<pair<int, int>, mint> memo;
    auto f = [&](int tmp, int K) -> mint {
        if(memo.count({tmp, K})){
            return memo[{tmp, K}];
        }
        mint res = 0;
        rep(x, 0, K+1){
            res += choose(K, x)*mint(2).pow(K).inv()/(tmp+x);
        }
        memo[{tmp, K}] = res;
        return res;
    };
    rep(i, 0, n){
        int l = 2*i, r = 2*i+1;
        rep(_, 0, 2){
            if(a[l] <= mx-2){
                ans[l] = 0;
            }else if(a[l] == mx-1){
                if(cnt[2][2] > 0){
                    ans[l] = 0;
                }else{
                    if(a[r] <= mx-2){
                        mint p1 = mint(2).pow(cnt[0][2]+cnt[1][2]+1).inv();
                        int tmp = cnt[1][2]*2+cnt[0][2]+cnt[1][1]+1;
                        mint p2 = f(tmp, cnt[0][1]-1);
                        ans[l] = p1*p2;
                    }else if(a[r] == mx-1){
                        mint p1 = mint(2).pow(cnt[0][2]+cnt[1][2]+1).inv();
                        int tmp = cnt[1][2]*2+cnt[0][2]+cnt[1][1];
                        mint p2 = f(tmp, cnt[0][1]);
                        ans[l] = p1*p2;
                    }else{
                        mint p1 = mint(2).pow(cnt[0][2]+cnt[1][2]).inv();
                        int tmp = cnt[1][2]*2+cnt[0][2]+cnt[1][1];
                        mint p2 = f(tmp, cnt[0][1]);
                        // cout << (p1*p2).val() << endl;
                        ans[l] = p1*p2;
                    }
                }
            }else{
                if(a[r] == mx){
                    // mint p1 = mint(2).inv();
                    // mint p2 = f(1, cnt[0][2]+cnt[1][2]+cnt[2][2]-1);
                    mint p1 = mint(2).inv();
                    mint p2 = f(cnt[2][2], cnt[0][2]+cnt[1][2]);
                    ans[l] += p1*p2;
                }else{
                    {
                        mint p1 = mint(2).inv();
                        mint p2 = f(1+cnt[2][2], cnt[0][2]+cnt[1][2]-1);
                        ans[l] += p1*p2;
                    }
                    if(cnt[2][2] == 0){
                        mint p1 = mint(2).pow(cnt[0][2]+cnt[1][2]).inv();
                        int tmp = cnt[1][2]*2+cnt[0][2]+cnt[1][1];
                        mint p2 = f(tmp, cnt[0][1]);
                        ans[l] += p1*p2;
                    }
                }
            }
            swap(l, r);
        }
    }

    rep(i, 0, 2*n){
        cout << ans[i].val() << ' ';
    }
    cout << endl;
    
    return 0;
}