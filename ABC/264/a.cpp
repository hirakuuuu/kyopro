#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc264/tasks/abc264_a

int main(){
    string s = "atcoder";
    int l, r; cin >> l >> r;
    cout << s.substr(l-1, r-l+1) << endl;
    
    return 0;
}