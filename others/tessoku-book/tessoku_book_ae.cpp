#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ae

int main(){
    ll n; cin >> n;
    ll cnt1 = n/3, cnt2 = n/5, cnt3 = n/15;

    cout << cnt1+cnt2-cnt3 << endl;
    
    return 0;
}