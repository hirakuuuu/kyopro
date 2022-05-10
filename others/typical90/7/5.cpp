#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_e

/*
n <= 10^18 → 繰り返し二乗法的な考え方が使えそう
・a[i][j] = 1（初期値）
・a[i][j]に1回の操作での変化を記録
・dp[i][j] = (下1桁が i で、b で割ったあまりが j である数字の数)
・n%2 == 1 の時、dp[i][j] *= a[i][j]
・a[i][j] *= a[i][j]
・n /= 2

    →　小課題2まではいけた
*/

int main(){
    ll n, b, k; cin >> n >> b >> k;
    vector<int> c(k);
    rep(i, 0, k) cin >> c[i];
    vector<vector<ll>> dp(b, vector<ll>(b)), dp_(b, vector<ll>(b));
    dp[0][0] = 1;
    vector<vector<ll>> a(b, vector<ll>(b)), a_(b, vector<ll>(b));
    rep(i, 0, b){
        rep(j, 0, k){
            a[i][(10*i+c[j])%b]++;
        }
    }

    // vector<ll> sum_l(b), sum_r(b);
    // rep(i, 0, b){
    //     rep(j, 0, b){
    //         sum_l[i] += a[i][j]; sum_l[i] %= MOD;
    //         sum_r[j] += a[i][j]; sum_r[j] %= MOD;
    //     }
    // }

    while(n){
        if(n%2){
            dp_ = dp;
            rep(i, 0, b){
                rep(j, 0, b){
                    dp[i][j] = 0;
                    rep(l, 0, b){
                        dp[i][j] += (dp_[i][l]*a[l][j])%MOD;
                        dp[i][j] %= MOD;
                    }
                }
            }
        }

        a_ = a;
        rep(i, 0, b){
            rep(j, 0, b){
                a[i][j] = 0;
                rep(l, 0, b){
                    a[i][j] += (a_[i][l]*a_[l][j])%MOD;
                    a[i][j] %= MOD;
                }
            }
        }

        n /= 2;
    }

    cout << dp[0][0] << endl;

    
    return 0;
}