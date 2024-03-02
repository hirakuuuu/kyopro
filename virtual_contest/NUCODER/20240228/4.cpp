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
// 

int main(){
    string s; cin >> s;
    int n = s.size();
    int k; cin >> k;
    vector<vector<ll>> dp(n+1, vector<ll>(k+1));
    dp[1][0] = 1;
    int f = 1;
    rep(i, 1, s[0]-'0'){
        dp[1][1]++;
    }
    rep(i, 1, n){
        // 0 を追加
        rep(j, 0, k+1){
            dp[i+1][j] += dp[i][j];
        }
        if(s[i]-'0' != 0 && f <= k){
            dp[i+1][f]++;
        }
        rep(j, 1, 10){
            rep(l, 0, k){
                dp[i+1][l+1] += dp[i][l];
            }
            if(j < s[i]-'0'){
                if(f+1 <= k) dp[i+1][f+1]++;
            }
            if(s[i]-'0' == j){
                f++;
            }
        }
    }
    ll ans = dp[n][k];
    if(f == k) ans++;
    cout << ans << endl;
    
    return 0;
}