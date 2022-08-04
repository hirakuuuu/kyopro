#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc262/tasks/abc262_c

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll num1 = 0, num2 = 0;
    ll ans = 0;

    // 数字とインデックスが一致しているもの
    rep(i, 0, n){
        if(a[i] == i+1) num1++;
    }
    ans += num1*(num1-1)/2;

    // 数字とインデックスが異なるもの
    rep(i, 0, n){
        if(a[a[i]-1] == i+1) num2++;
    }
    ans += (num2-num1)/2;

    cout << ans << endl;
    return 0;
}