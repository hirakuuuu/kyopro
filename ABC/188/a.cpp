#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc188/tasks/abc188_a

int main(){
    int x, y; cin >> x >> y;
    if(abs(x-y) < 3) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}