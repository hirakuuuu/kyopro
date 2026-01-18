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

// nPk
mint permutation(int n, int k){
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
    string s; cin >> s;
    int n = (int)s.size();

    int cnt_q = 0;
    rep(i, 0, n){
        if(s[i] == '?') cnt_q++;
    }

    int r = n;
    vector<int> cnt_u(26);
    rep(i, 0, n){
        if(isupper(s[i])){
            cnt_u[s[i]-'A']++;
            if(cnt_u[s[i]-'A'] == 2){
                r = i;
                break;
            }
        }
    }

    // 後ろからDP
    vector<vector<mint>> dp(n+1, vector<mint>(3));
    dp[n][0] = 1;
    rrep(i, n-1, 0){
        if(s[i] == '?'){
            dp[i][0] += dp[i+1][0]*26;
            dp[i][1] += dp[i+1][0]*26+dp[i+1][1]*26;
            dp[i][2] += dp[i+1][2]*52+dp[i+1][1]*26;
        }else if(isupper(s[i])){
            dp[i][1] += dp[i+1][0]+dp[i+1][1];
            dp[i][2] += dp[i+1][2];
        }else{
            dp[i][0] += dp[i+1][0];
            dp[i][2] += dp[i+1][1]+dp[i+1][2];
        }
    }

    mint ans = mint(52).pow(cnt_q);
    cnt_q = 0;
    int cnt_U = 0;
    mint acc = 0;
    rep(l, 0, r){
        if(islower(s[l])) continue;
        if(s[l] == '?') cnt_q++, acc *= 52;
        if(isupper(s[l])) cnt_U++;

        mint tot = mint(52).pow(cnt_q)-acc;

        rep(i, cnt_U, 27){
            if(i > l+1) continue;
            if(i-cnt_U > cnt_q) continue;
            // cout << i << ' ' << (permutation(26-cnt_U, i-cnt_U)).val() << endl;
            tot -= choose(cnt_q, i-cnt_U)*permutation(26-cnt_U, i-cnt_U)*mint(26).pow(cnt_q-(i-cnt_U));
        }

        ans -= tot*dp[l+1][2];
        acc += tot;

        // cout << l << ' ' << tot.val() << ' ' << ans.val() << endl;
    }
    // r+1;
    if(r < n){
        mint tmp = mint(52).pow(cnt_q)-acc;
        ans -= tmp*dp[r+1][2];
        // cout << dp[r+1][2].val() << endl;;
    }
    cout << ans.val() << endl;
    
    return 0;
}