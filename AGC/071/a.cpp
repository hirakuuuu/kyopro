#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 4e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> acc(n+1);
    rep(i, 0, n) acc[i+1] = (acc[i]^a[i]);

    // dp[l][r] := f(l, r, acc[r]^acc[l]) ([l, r) が奇数長) 
    //             f(l, r, 0) ([l, r) が偶数長)
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    rep(len, 1, n+1){
        rep(l, 0, n){
            int r = l+len;
            if(r > n) break;

            if(len == 1){
                dp[l][r] = 0;
                continue;
            }

            ll res = INF;
            if(len%2){
                rep(m, l+1, r) chmin(res, dp[l][m]+dp[m][r]);
            }else{
                rep(m, l+1, r){
                    if((m-l)%2){
                        chmin(res, dp[l][m]+dp[m][r]+(acc[r]^acc[l])*2);
                    }else{
                        chmin(res, dp[l][m]+dp[m][r]);
                    }
                }
            }
            dp[l][r] = res;
        }
    }

    if(n%2) dp[0][n] += acc[n];
    cout << dp[0][n] << endl;
   
    return 0;
}