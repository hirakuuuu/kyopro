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
// https://atcoder.jp/contests/abc308/tasks/abc308_e

int main(){
    int n; cin >> n;
    vector<ll> a(n+1);
    rep(i, 1, n+1) cin >> a[i];
    string s; cin >> s;
    string mex = "MEX";
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(5, vector<ll>((1<<3))));
    dp[0][0][0] = 1;
    rep(i, 1, n+1){
        rep(j, 0, 4){
            rep(k, 0, (1<<3)){
                dp[i][j][k] += dp[i-1][j][k];
            }
            if(j > 0 && s[i-1] == mex[j-1]){
                rep(k, 0, (1<<3)){
                    dp[i][j][k|(1<<a[i])] += dp[i-1][j-1][k];
                }
            }
        }
    }

    ll ans = 0;
    rep(i, 0, (1<<3)){
        if(dp[n][3][i] == 0) continue;
        rep(j, 0, 4){
            if((i&(1<<j)) == 0){
                ans += j*dp[n][3][i];
                break;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}