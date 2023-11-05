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
// https://atcoder.jp/contests/abc155/tasks/abc155_e

int main(){
    string s; cin >> s;
    reverse(s.begin(), s.end());
    int n = s.size();

    vector<vector<ll>> dp(n+1, vector<ll>(2, INF));
    dp[0][0] = 0;
    rep(i, 1, n+1){
        rep(j, 0, 2){
            ll tmp = (s[i-1]-'0');
            if(j+tmp == 10){
                chmin(dp[i][1], dp[i-1][j]);
            }else{
                if(j) tmp++;
                chmin(dp[i][0], dp[i-1][j]+tmp);
                chmin(dp[i][1], dp[i-1][j]+10-tmp);
            }
        }
    }
    cout << min(dp[n][0], dp[n][1]+1) << endl;
    return 0;
}