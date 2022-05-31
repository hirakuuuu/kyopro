#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc065/tasks/abc065_a

int main(){
    int x, a, b; cin >> x >> a >> b;
    if(b-a <= 0) cout << "delicious" << endl;
    else if(b-a-x <= 0) cout << "safe" << endl;
    else cout << "dangerous" << endl;
    
    return 0;
}