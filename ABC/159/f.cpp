#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
求めるものは (L, x_1, x_2, ... , x_k, R) の数と言い換えられる
L, LR がそれぞれ確定した状態を持つような DP をすることで解ける

多項式的な考え方の方が分かりやすかった
*/

int main(){
    int n, s; cin >> n >> s;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<vector<vector<mint>>> dp(n+1, vector<vector<mint>>(s+1, vector<mint>(3)));
    dp[0][0][0] = 1;
    rep(i, 0, n){
        rep(j, 0, s+1){
            rep(k, 0, 3){
                rep(l, k, 3){
                    dp[i+1][j][l] += dp[i][j][k];
                    if(j-a[i] >= 0 && l != 0 && k != 2) dp[i+1][j][l] += dp[i][j-a[i]][k];
                }
            }
        }
    }

    cout << dp[n][s][2].val() << endl;


    
    
    return 0;
}