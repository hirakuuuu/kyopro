#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n, m; cin >> n >> m;
    vector<int> c(m);
    rep(i, 0, m) cin >> c[i];
    sort(c.begin(), c.end());
    vector<int> dp(n+1);
    rep(i, 0, n+1) dp[i] = i;
    rep(i, 1, m){
        rep(j, 1, n+1){
            if(j-c[i] >= 0) dp[j] = min(dp[j], dp[j-c[i]]+1);
        }
    }
    cout << dp[n] << endl;
  
}