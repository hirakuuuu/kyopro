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
// https://atcoder.jp/contests/abc074/tasks/arc083_a

int main(){
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;

    vector<vector<bool>> dp(f+1, vector<bool>(f+1));
    dp[0][0] = true;
    rep(i, 0, f){
        rep(j, 0, f){
            if(dp[i][j]){
                if(i+100*a+j <= f) dp[i+100*a][j] = 1;
                if(i+100*b+j <= f) dp[i+100*b][j] = 1;
                if(i+j+c <= f) dp[i][j+c] = 1;
                if(i+j+d <= f) dp[i][j+d] = 1;
            }
        }
    }

    int mx_i = 100*a, mx_j = 0;
    pair<int, int> ans = {mx_i, mx_j};
    rep(i, 1, f+1){
        rep(j, 0, f+1){
            if(dp[i][j]){
                if(j <= e*(i/100) && (i+j)*mx_j < j*(mx_j+mx_i)){
                    mx_i = i;
                    mx_j = j;
                    ans = {i, j};
                }
            }
        }
    }

    cout << ans.first+ans.second << ' ' << ans.second << endl;
    
    return 0;
}