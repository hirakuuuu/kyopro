#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_aq

ll bimpower(ll a, ll b, ll m){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1){
            res *= a;
            res %= m;
        }
        b /= 2;
        a *= a;
        a %= m;
    }
    return res;
}

int main(){
    ll a, b; cin >> a >> b;
    cout << bimpower(a, b, MOD) << endl;
    
    return 0;
}