#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_dd

int main(){
    ll n; cin >> n;
    ll ans = 0;
    ans += n/3;
    ans += n/5;
    ans += n/7;
    ans -= n/15;
    ans -= n/21;
    ans -= n/35;
    ans += n/105;
    cout << ans << endl;
    
    return 0;
}