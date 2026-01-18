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

int main(){
    int n, m, l; cin >> n >> m >> l;
    vector<mint> dp(n+1);
    dp[0] = 1;
    // 1/(1-x)*(1-x^2)\dots(1-x^l) の係数を計算
    rep(i, 1, l+1){
        rep(j, 0, n-i+1){
            dp[j+i] += dp[j];
        }
    }
    cout << dp[n].val() << endl;
    
    rep(i, 2, m-l+2){
        // 1-x^(i-1) を掛ける
        rrep(j, n, 0){
            if(j >= i-1) dp[j] -= dp[j-(i-1)];
        }
        // 1/(1-x^{i+l-1}) を掛ける
        rep(j, 0, n+1){
            if(j+(i+l-1) > n) break;
            dp[j+(i+l-1)] += dp[j];
        }
        cout << dp[n].val() << endl;
    }

    
    return 0;
}