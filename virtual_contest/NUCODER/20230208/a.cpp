#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    rep(i, 1, n+1) cin >> a[i];
    rep(i, 1, n+1) cin >> b[i];

    vector<vector<ll>> dp(n+1, vector<ll>(3005));
    rep(i, 0, 3005) dp[0][i] = 1;
    rep(i, 1, n+1){
        rep(j, 0, 3005){
            if(j > 0) dp[i][j] = dp[i][j-1];
            if(a[i] <= j and j <= b[i]){
                dp[i][j] += dp[i-1][j];
            }
            dp[i][j] %= mod_num;
        }
    }

    cout << dp[n][b[n]] << endl;

    
    return 0;
}