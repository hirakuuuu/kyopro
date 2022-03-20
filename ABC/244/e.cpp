#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n, m, k, s, t, x; cin >> n >> m >> k >> s >> t >> x;
    vector<int> u(m), v(m);
    rep(i, 0, m){
        cin >> u[i] >> v[i];
    }
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(k+1, vector<int>(n+1)));
    int pos = s;
    dp[0][0][pos] = 1;
    rep(i, 1, k+1){
        rep(l, 0, 2){
            rep(j, 0, m){
                if(u[j] == x){
                    dp[l^1][i][v[j]] = (dp[l^1][i][v[j]]+dp[l][i-1][u[j]])%mod;
                    dp[l][i][u[j]] = (dp[l][i][u[j]]+dp[l][i-1][v[j]])%mod;
                }else if(v[j] == x){
                    dp[l^1][i][u[j]] = (dp[l^1][i][u[j]]+dp[l][i-1][v[j]])%mod;
                    dp[l][i][v[j]] = (dp[l][i][v[j]]+dp[l][i-1][u[j]])%mod;
                }else{
                    dp[l][i][u[j]] = (dp[l][i][u[j]]+dp[l][i-1][v[j]])%mod;
                    dp[l][i][v[j]] = (dp[l][i][v[j]]+dp[l][i-1][u[j]])%mod;
                }
            }
        }
    }
    // rep(i, 0, 2){
    //     rep(j, 0, k+1){
    //         rep(l, 1, n+1){
    //             cout << dp[i][j][l] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;

    // }

    cout << dp[0][k][t] << endl;
}