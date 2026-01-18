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
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
        if(a[i] > 0) a[i]--;
    }

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    vector<mint> dp(2);
    if(a[0] == -1){
        dp[0] = n-1;
        dp[1] = 1;
    }else if(a[0] == 1){
        dp[1] = 1;
    }else{
        dp[0] = 1;
    }

    rep(i, 1, n-1){
        vector<mint> ndp(2);
        if(a[i] == i+1){
            ndp[1] = dp[1];
        }else if(a[i] == -1){
            ndp[0] = dp[1]*(n-1)+dp[0];
            ndp[1] = dp[1];
        }else if(a[i] == i-1){
            ndp[0] = dp[1]+dp[0];
        }else{
            ndp[0] = dp[1];
        }
        swap(ndp, dp);
    }

    // rep(i, 0, 2){
    //     cout << dp[i].val() << ' ';
    // }
    // cout << endl;
    
    mint ans = 0;
    if(a[n-1] == -1){
        ans += n*dp[1]+dp[0];
    }else if(a[n-1] == n-2){
        ans += dp[0]+dp[1];
    }else{
        ans += dp[1];
    }
    cout << ans.val() << endl;
    return 0;
}