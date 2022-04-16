#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc248/tasks/abc248_b

int main(){
    ll a, b, k; cin >> a >> b >> k;
    ll s = a, n = 0;
    while(s < b){
        s *= k;
        n++;
    }
    cout << n << endl;
    
    return 0;
}