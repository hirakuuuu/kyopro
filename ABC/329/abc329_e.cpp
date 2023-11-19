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
// https://atcoder.jp/contests/abc329/tasks/abc329_e

int main(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    string t; cin >> t;

    vector<vector<bool>> dp(n, vector<bool>(m));
    if(s[0] == t[0]) dp[0][0] = true;
    
    rep(i, 1, n){
        rep(j, 0, m){
            if(dp[i-1][j] && s[i-1] == t[j]){
                if(j != m-1){
                    if(s[i] == t[j+1]) dp[i][j+1] = true;
                }else{
                    rep(k, 0, m){
                        if(k <= i && i <= n-m+k && s[i] == t[k]) dp[i][k] = true;
                    }
                }
                if(i <= n-m && s[i] == t[0]) dp[i][0] = true;
            }
        }
    }

    if(dp[n-1][m-1]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}