#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc184/tasks/abc184_d

double dp[105][105][105];

int main(){
    int a, b, c; cin >> a >> b >> c;

    for(int i = 99; i >= a; i--){
        for(int j = 99; j >= b; j--){
            for(int k = 99; k >= c; k--){
                int total = i+j+k;
                dp[i][j][k] += (double)(dp[i+1][j][k]+1)*i/total;
                dp[i][j][k] += (double)(dp[i][j+1][k]+1)*j/total;
                dp[i][j][k] += (double)(dp[i][j][k+1]+1)*k/total;
            }
        }
    }

    printf("%.10f\n", dp[a][b][c]);

    
    return 0;
}