#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc027/tasks/arc027_3


int main(){
    ll x, y; cin >> x >> y;
    ll n; cin >> n;
    vector<ll> t(n+1), h(n+1);
    rep(i, 1, n+1){
        cin >> t[i] >> h[i];
    }

    vector<vector<ll>> dp(x+1, vector<ll>(x+y+1));
    vector<vector<ll>> dp_(x+1, vector<ll>(x+y+1));

    rep(i, 1, n+1){
        rep(j, 1, min(x, (ll)i)+1){
            rep(k, 0, y+(x-j)+1){
                if(k >= t[i]-1) dp_[j][k] = max(dp[j][k], dp[j-1][k-(t[i]-1)]+h[i]);
                else dp_[j][k] = dp[j][k];
            }
        }
        dp = dp_;
    }

    ll ans = 0;

    rep(j, 0, x+1){
        rep(k, 0, x+y+1){
            ans = max(ans, dp[j][k]);
        }
    }

    cout << ans << endl;


    
    return 0;
}