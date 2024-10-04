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

/*
i 番目と i+1 番目の間でかかるコストはDPで求まる O(h^2)
各隣接する列について、この最小値を達成するように操作列を構成できる（順番に相対順序を保つように挿入すれば良いだけ）
全体で O(wh^2)
*/

int main(){
    int h, w; cin >> h >> w;
    vector<string> c(h);
    rep(i, 0, h) cin >> c[i];

    vector<vector<vector<int>>> cost(w, vector<vector<int>>(h+1, vector<int>(h+1)));
    rep(i, 0, w-1){
        // i 列目と i+1 列目についてのコストを計算する
        // cost[i][j][k] := i 列目が j 段, i+1 列目が k 段 残っているときにかかるコスト
        rep(j, 1, h+1){
            rep(k, 1, h+1){
                cost[i][j][k] = cost[i][j-1][k-1]+(c[j-1][i]==c[k-1][i+1]);
            }
        }
    }
    int ans = 0;
    rep(i, 0, w-1){
        vector<vector<int>> dp(h+1, vector<int>(h+1));
        // dp[j][k] := i 列目が j 段, i+1 列目が k 段 残っているときに最後まで操作してかかるコストの最小値
        rep(j, 1, h+1){
            rep(k, 1, h+1){
                dp[j][k] = min(dp[j-1][k], dp[j][k-1])+cost[i][j][k];
            }
        }
        ans += dp[h][h];
    }
    cout << ans << endl;
    return 0;
}