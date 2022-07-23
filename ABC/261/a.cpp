#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc261/tasks/abc261_a

int main(){
    int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
    if(r1 <= l2 or r2 <= l1) cout << 0 << endl;
    else cout << min(r1, r2)-max(l1, l2) << endl;
    
    return 0;
}