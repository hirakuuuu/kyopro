#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc101/tasks/abc101_b

int main(){
    int n; cin >> n;
    int m = n, s = 0;
    while(m > 0){
        s += m%10;
        m /= 10;
    }
    if(n%s == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}