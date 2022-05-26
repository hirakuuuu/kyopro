#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc196/tasks/abc196_c

ll f(ll i){
    ll o = 10;
    ll j = i;
    while(j/10 > 0){
        o *= 10;
        j /= 10;
    }
    return i*o+i;
}

int main(){
    ll n; cin >> n;
    ll i = 1, cnt = 0;
    while(f(i) <= n){
        i++;
        cnt++;
    }
    cout << cnt << endl;
    
    return 0;
}