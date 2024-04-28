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
// https://atcoder.jp/contests/abc312/tasks/abc312_e

int main(){
    int n; cin >> n;
    vector<vector<vector<int>>> dp(100, vector<vector<int>>(100, vector<int>(100, -1)));
    rep(ind, 0, n){
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        rep(i, x1, x2){
            rep(j, y1, y2){
                rep(k, z1, z2){
                    dp[i][j][k] = ind;
                }
            }
        }
    }
    vector<set<int>> ans(n);
    rep(i, 0, n){
        ans[i].insert(-1);
        ans[i].insert(i);
    }
    rep(i, 0, 100){
        rep(j, 0, 100){
            rep(k, 0, 100){
                if(i+1 < 100 && dp[i+1][j][k] != -1) ans[dp[i+1][j][k]].insert(dp[i][j][k]);
                if(0 <= i-1 && dp[i-1][j][k] != -1) ans[dp[i-1][j][k]].insert(dp[i][j][k]);
                if(j+1 < 100 && dp[i][j+1][k] != -1) ans[dp[i][j+1][k]].insert(dp[i][j][k]);
                if(0 <= j-1 && dp[i][j-1][k] != -1) ans[dp[i][j-1][k]].insert(dp[i][j][k]);
                if(k+1 < 100 && dp[i][j][k+1] != -1) ans[dp[i][j][k+1]].insert(dp[i][j][k]);
                if(0 <= k-1 && dp[i][j][k-1] != -1) ans[dp[i][j][k-1]].insert(dp[i][j][k]);
            }
        }
    }
    rep(i, 0, n){
        cout << ans[i].size()-2 << endl;
    }
    return 0;
}