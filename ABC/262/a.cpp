#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc262/tasks/abc262_a

int main(){
    int y; cin >> y;
    cout << y+((2-(y%4))+4)%4 << endl;
    
    return 0;
}