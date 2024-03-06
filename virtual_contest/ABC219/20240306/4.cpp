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
    int n; cin >> n;
    int x, y; cin >> x >> y;
    vector<vector<int>> dp(x+1, vector<int>(y+1, IINF));
    dp[0][0] = 0;
    rep(i, 0, n){
        int a, b; cin >> a >> b;
        vector<vector<int>> dp_ = dp;
        rep(j, 0, x+1){
            rep(k, 0, y+1){
                chmin(dp[min(x, j+a)][min(y, k+b)], dp_[j][k]+1);
            }
        }
    }
    if(dp[x][y] == IINF) cout << -1 << endl;
    else cout << dp[x][y] << endl;
    return 0;
}