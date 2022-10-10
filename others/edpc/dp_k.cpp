#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/dp/tasks/dp_k

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    vector<bool> dp(k+1);
    rep(i, a[1], k+1){
        rep(j, 1, n+1){
            if(a[j] <= i){
                dp[i] = (dp[i] or !dp[i-a[j]]);
            }
        }
    }

    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}