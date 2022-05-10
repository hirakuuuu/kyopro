#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_k

/*

*/

ll dp[5001][5001];

int main(){
    int n; cin >> n;
    vector<vector<ll>> task(n+1, vector<ll>(3));
    rep(i, 1, n+1){
        cin >> task[i][0] >> task[i][1] >> task[i][2];
    }

    sort(task.begin(), task.end());

    rep(i, 1, n+1){
        rep(j, 1, 5001){
            if(j <= task[i][0] and j >= task[i][1]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-task[i][1]]+task[i][2]);
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    cout << dp[n][5000] << endl;
    
    return 0;
}