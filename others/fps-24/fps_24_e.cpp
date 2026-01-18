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
    int n, m; cin >> n >> m;
    vector<mint> fact(n+1), finv(n+1);
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    rep(i, 2, n+1){
        fact[i] = fact[i-1]*i;
        finv[i] = fact[i].inv();
    }
    vector<mint> dp(n+1);
    vector<mint> ndp(n+1);
    dp[0] = 1;
    rep(i, 1, m+1){
        rep(j, 0, n+1){
            ndp[j] = 0;
        }
        rep(j, 0, i+1){
            if(j > n) break; 
            rep(k, 0, n+1){
                if(j+k > n) break;
                ndp[j+k] += dp[k]*finv[j];
            }
        }
        swap(dp, ndp);        
    }
    cout << (dp[n]*fact[n]).val() << endl;

    
    return 0;
}