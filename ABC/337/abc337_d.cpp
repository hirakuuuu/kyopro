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
// https://atcoder.jp/contests/abc337/tasks/abc337_d

int main(){
    int h, w, k; cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    int ans = IINF;
    vector<vector<pair<int, int>>> dp(h, vector<pair<int, int>>(w));
    rep(i, 0, h){
        if(s[i][0] == 'o') dp[i][0] = {1, 0};
        else if(s[i][0] == '.') dp[i][0] = {1, 1};
        else if(s[i][0] == 'x') dp[i][0] = {0, 0};
        rep(j, 1, w){
            if(s[i][j] == 'o'){
                if(dp[i][j-1].first < k) dp[i][j] = {dp[i][j-1].first+1, dp[i][j-1].second};
                else{
                    if(s[i][j-k] == 'o') dp[i][j] = dp[i][j-1];
                    else if(s[i][j-k] == '.') dp[i][j] = {k, dp[i][j-1].second-1};
                }
            }else if(s[i][j] == '.'){
                if(dp[i][j-1].first < k) dp[i][j] = {dp[i][j-1].first+1, dp[i][j-1].second+1};
                else{
                    if(s[i][j-k] == '.') dp[i][j] = dp[i][j-1];
                    else if(s[i][j-k] == 'o') dp[i][j] = {k, dp[i][j-1].second+1};
                }
            }else if(s[i][j] == 'x') dp[i][j] = {0, 0};
        }

        rep(j, 0, w){
            if(dp[i][j].first == k) chmin(ans, dp[i][j].second);
        }
    }

    rep(i, 0, w){
        if(s[0][i] == 'o') dp[0][i] = {1, 0};
        else if(s[0][i] == '.') dp[0][i] = {1, 1};
        else if(s[0][i] == 'x') dp[0][i] = {0, 0};
        rep(j, 1, h){
            if(s[j][i] == 'o'){
                if(dp[j-1][i].first < k) dp[j][i] = {dp[j-1][i].first+1, dp[j-1][i].second};
                else{
                    if(s[j-k][i] == 'o') dp[j][i] = dp[j-1][i];
                    else if(s[j-k][i] == '.') dp[j][i] = {k, dp[j-1][i].second-1};
                }
            }else if(s[j][i] == '.'){
                if(dp[j-1][i].first < k) dp[j][i] = {dp[j-1][i].first+1, dp[j-1][i].second+1};
                else{
                    if(s[j-k][i] == '.') dp[j][i] = dp[j-1][i];
                    else if(s[j-k][i] == 'o') dp[j][i] = {k, dp[j-1][i].second+1};
                }
            }else if(s[j][i] == 'x') dp[j][i] = {0, 0};
        }

        rep(j, 0, h){
            if(dp[j][i].first == k) chmin(ans, dp[j][i].second);
        }
    }
    
    if(ans == IINF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}