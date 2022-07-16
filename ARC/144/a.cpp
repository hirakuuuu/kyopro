#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tasks/arc144_a


int main(){
    ll n; cin >> n;
    cout << 2*n << endl;

    if(n%4){
        cout << n%4;
    }
    rep(i, 0, n/4){
        cout << 4;
    }
    cout << endl;
    return 0;
}