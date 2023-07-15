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
// https://atcoder.jp/contests/abc310/tasks/abc310_e

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n);
    rep(i, 0, n) a[i] = s[i]-'0';

    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[0][a[0]] = 1;
    ll ans = a[0];

    rep(i, 1, n){
        if(a[i]){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = dp[i-1][0];
        }else{
            dp[i][0] = 0;
            dp[i][1] = dp[i-1][1]+dp[i-1][0];
        }
        dp[i][a[i]]++;
        ans += dp[i][1];
    }
    cout << ans << endl;
    
    return 0;
}