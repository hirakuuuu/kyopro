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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    rep(i, 1, n+1) cin >> a[i];
    sort(a.begin(), a.end());

    vector<vector<int>> dp(n+1, vector<int>(35, IINF));
    rep(i, 0, 35) dp[0][i] = 0;
    rep(i, 0, n){
        int l = upper_bound(a.begin(), a.end(), a[i+1]/2)-a.begin();
        l--;
        rep(j, 0, 35){
            chmin(dp[i+1][j], dp[i][j]+1);
            if(j > 0) chmin(dp[i+1][j], dp[l][j-1]);
        }
    }
    rep(i, 0, 35){
        if(dp[n][i] <= k){
            cout << i << ' ' << dp[n][i] << endl;
            break;
        }
    }

    
    return 0;
}