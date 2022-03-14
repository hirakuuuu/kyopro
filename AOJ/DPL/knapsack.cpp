#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n, W; cin >> n >> W;
    vector<int> v(n), w(n);
    rep(i, 0, n) cin >> v[i] >> w[i];

    vector<int> dp(W+1);
    rep(i, 0, n){
        vector<int> cp = dp;
        rep(j, 0, W+1){
            if(j >= w[i]) cp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
        dp = cp;
    }
    cout << dp[W] << endl; 
}