#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<int>> dp(n+1, vector<int>(n+1));
    rep(i, 0, n-2) dp[i][i+3] = max(0, a[i]+a[i+1]+a[i+2]);

    rep(k, 4, n+1){
        rep(l, 0, n){
            int r = l+k;
            if(r > n) break;

            rep(i, l+1, r){
                chmax(dp[l][r], dp[l][i]+dp[i][r]);
            }
            if((r-l)%3 == 0){
                rep(i, l+1, r){
                    if((i-l-1)%3 == 0 && (r-1-i-1)%3 == 0){
                        chmax(dp[l][r], dp[l+1][i]+dp[i+1][r-1]+a[l]+a[i]+a[r-1]);
                    }
                }
            }
        }
    }
    cout << dp[0][n] << endl;
    
    return 0;
}