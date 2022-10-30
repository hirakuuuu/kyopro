#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int k; cin >> k;
    if(k%9){
        cout << 0 << endl;
        return 0;
    }

    vector<int> dp(100005);
    dp[0] = 1;
    rep(i, 1, k+1){
        rep(j, 1, 10){
            if(i >= j){
                dp[i] = (dp[i] + dp[i-j])%MOD;
            }
        }
    }
    cout << dp[k] << endl;
}