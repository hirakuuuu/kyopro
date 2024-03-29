#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_az

int main(){
    int n; cin >> n;
    ll ans = 1;
    rep(i, 0, n){
        ll total = 0;
        rep(j, 0, 6){
            int d; cin >> d;
            total += d;
        }
        ans *= total;
        ans %= MOD;
    }
    cout << ans << endl;
    
    return 0;
}