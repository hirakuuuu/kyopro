#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_a

int main(){
    ll n; cin >> n;
    if(n%2 == 0) cout << n*(n-1)/2 << endl;
    else cout << n*(n-1)/2-1 << endl;
    return 0;
}