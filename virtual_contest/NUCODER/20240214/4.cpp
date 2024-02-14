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
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];
    vector<vector<int>> dp(h, vector<int>(w));
    auto f = [&](int i, int j)->int {
        if(s[i][j] == '+') return 1;
        return -1;
    };
    rrep(i, h-1, 0){
        rrep(j, w-1, 0){
            if((i+j)%2 == 0){
                if(i != h-1 && j != w-1) dp[i][j] = max(dp[i+1][j]+f(i+1, j), dp[i][j+1]+f(i, j+1));
                else if(i != h-1) dp[i][j] = dp[i+1][j]+f(i+1, j);
                else if(j != w-1) dp[i][j] = dp[i][j+1]+f(i, j+1);
            }else{
                if(i != h-1 && j != w-1) dp[i][j] = min(dp[i+1][j]-f(i+1, j), dp[i][j+1]-f(i, j+1));
                else if(i != h-1) dp[i][j] = dp[i+1][j]-f(i+1, j);
                else if(j != w-1) dp[i][j] = dp[i][j+1]-f(i, j+1);
            }
        }
    }

    if(dp[0][0] > 0) cout << "Takahashi" << endl;
    else if(dp[0][0] < 0) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
    return 0;
}