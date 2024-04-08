#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int h, w; cin >> h >> w;
    vector<string> c(h);
    rep(i, 0, h) cin >> c[i];
    vector<vector<int>> dp(h+1, vector<int>(w+1, -IINF));
    dp[1][1] = 1;
    int ans = 1;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            if(c[i-1][j-1] == '#') continue;
            if(i-1 >= 0) chmax(dp[i][j], dp[i-1][j]+1);
            if(j-1 >= 0) chmax(dp[i][j], dp[i][j-1]+1);
            chmax(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    
    return 0;
}