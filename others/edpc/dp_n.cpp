#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/dp/tasks/dp_n

ll n, a[405], a_sum[405], dp[405][405];

ll score(int l, int r){
    if(dp[l][r] >= 0) return dp[l][r];
    if(l == r) return dp[l][r] = 0;

    ll min_score = (1LL<<60);
    rep(m, l, r){
        min_score = min(min_score, score(l, m)+score(m+1, r)+(a_sum[r]-a_sum[l-1]));
    }

    return dp[l][r] = min_score;

}


int main(){
    cin >> n;
    rep(i, 1, n+1){
        cin >> a[i];
        a_sum[i] = a_sum[i-1]+a[i];
    }

    rep(i, 0, n+1){
        rep(j, 0, n+1) dp[i][j] = -1;
    }

    cout << score(1, n) << endl;
    
    return 0;
}