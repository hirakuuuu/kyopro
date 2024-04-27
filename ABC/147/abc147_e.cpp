#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int h, w; cin >> h >> w;
    vector<vector<int>> a(h+1, vector<int>(w+1));
    vector<vector<int>> b(h+1, vector<int>(w+1));
    rep(i, 1, h+1) rep(j, 1, w+1) cin >> a[i][j];
    rep(i, 1, h+1) rep(j, 1, w+1) cin >> b[i][j];
    vector<vector<vector<bool>>> dp(h+1, vector<vector<bool>>(w+1, vector<bool>(6405)));
    dp[0][1][0] = true;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            rep(k, 0, 6405){
                if(dp[i-1][j][k] || dp[i][j-1][k]){
                    int tmp = abs(a[i][j]-b[i][j]);
                    if(abs(k+tmp) <= 6400) dp[i][j][abs(k+tmp)] = true;
                    if(abs(k-tmp) <= 6400) dp[i][j][abs(k-tmp)] = true;
                }
            }
        }
    }
    rep(i, 0, 6405){
        if(dp[h][w][i]){
            cout << i << endl;
            break;
        }
    }
    return 0;
}