#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<vector<ll>> dp(n+1, vector<ll>(2));
    dp[0][0] = dp[0][1] = 1;
    rep(i, 1, n+1){
        string s; cin >> s;
        if(s == "AND"){
            dp[i][0] = 2*dp[i-1][0]+dp[i-1][1];
            dp[i][1] = dp[i-1][1];
        }else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][0]+2*dp[i-1][1];  
        }
    }
    cout << dp[n][1] << endl;
    
    return 0;
}