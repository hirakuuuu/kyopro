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
// https://atcoder.jp/contests/abc055/tasks/arc069_b

int main(){
    int n; cin >> n;
    string s; cin >> s;
    string sw = "SW";

    vector<string> dp(4);
    dp[0] = "SS";
    dp[1] = "SW";
    dp[2] = "WS";
    dp[3] = "WW";
    rep(i, 0, 4){
        rep(j, 1, n){
            if(dp[i][j] == 'S'){
                if(s[j] == 'o') dp[i] += dp[i][j-1];
                else dp[i] += (dp[i][j-1] == 'S' ? 'W' : 'S');
            }else{
                if(s[j] == 'x') dp[i] += dp[i][j-1];
                else dp[i] += (dp[i][j-1] == 'S' ? 'W' : 'S');
            }
        }
        if(dp[i][0] == dp[i][n]){
            if(dp[i][0] == 'S' && (s[0] == 'o')^(dp[i][1] != dp[i][n-1])){
                cout << dp[i].substr(0, n) << endl;
                return 0;
            }else if(dp[i][0] == 'W' && (s[0] == 'o')^(dp[i][1] == dp[i][n-1])){
                cout << dp[i].substr(0, n) << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    
    return 0;
}