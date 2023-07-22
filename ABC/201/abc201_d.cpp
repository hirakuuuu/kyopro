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
// https://atcoder.jp/contests/abc201/tasks/abc201_d

int main(){
    int h, w; cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, 0, h){
        rep(j, 0, w){
            char c; cin >> c;
            if(c == '+') a[i][j]++;
            else a[i][j]--;
        }
    }

    vector<vector<int>> dp(h, vector<int>(w));
    rrep(s, h+w-2, 0){
        rep(i, 0, s+1){
            if(i >= h || s-i >= w) continue;
            int j = s-i;
            dp[i][j] = a[i][j];
            if(i+1 < h && j+1 < w) dp[i][j] -= max(dp[i+1][j], dp[i][j+1]);
            else if(i+1 < h) dp[i][j] -= dp[i+1][j];
            else if(j+1 < w) dp[i][j] -= dp[i][j+1];
        }
    }

    dp[0][0] -= a[0][0];
    if(dp[0][0] > 0) cout << "Aoki" << endl;
    else if(dp[0][0] < 0) cout << "Takahashi" << endl;
    else cout << "Draw" << endl;




    
    return 0;
}