#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

/*
m*n行列とn*l行列の積におけるスカラー乗算の回数はm*n*l
A(=m*n)B(=n*l)C(=l*k)という積において、スカラー乗算の回数の最小値は 
min((m*n*l)+m*l*k, m*n*k+(n*l*k))=((ABを先に計算する場合), (BCを先に計算する場合))
→ どこで区切るかでdpしてあげると良さそう
*/


int main(){
    int n; cin >> n;
    vector<int> p(n+1);
    rep(i, 0, n) cin >> p[i] >> p[i+1];
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    rep(d, 2, n+1){
        rep(i, 1, n-d+2){
            int j = i+d-1;
            dp[i][j] = MOD;
            rep(k, i, j){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }
    cout << dp[1][n] << endl;
}