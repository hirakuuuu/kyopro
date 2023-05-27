#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc303/tasks/abc303_d

int main(){
    ll x, y, z; cin >> x >> y >> z;
    string s; cin >> s;
    ll n = s.size();

    vector<vector<ll>> dp(n+1, vector<ll>(2));
    dp[0][0] = 0;
    dp[0][1] = z;
    rep(i, 1, n+1){
        if(s[i-1] == 'A'){
            dp[i][0] = min(dp[i-1][0]+y, dp[i-1][1]+z+min(x, y));
            dp[i][1] = min(dp[i-1][1]+x, dp[i-1][0]+z+min(x, y));
        }else{
            dp[i][0] = min(dp[i-1][0]+x, dp[i-1][1]+z+min(x, y));
            dp[i][1] = min(dp[i-1][1]+y, dp[i-1][0]+z+min(x, y));
        }
    }

    cout << min(dp[n][0], dp[n][1]) << endl;

    
    return 0;
}