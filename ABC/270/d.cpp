#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc270/tasks/abc270_d

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(k);
    rep(i, 0, k) cin >> a[i];

    vector<int> dp(n+1);

    rep(i, 1, n+1){
        rep(j, 1, k+1){
            if(i >= a[j-1]) dp[i] = max(dp[i], a[j-1]+(i-a[j-1])-dp[i-a[j-1]]);
        }
    }

    cout << dp[n] << endl;


    return 0;
}