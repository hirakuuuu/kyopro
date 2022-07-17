#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc260/tasks/abc260_c

ll x, y;
ll f(ll n, ll r){
    ll res = 0;
    if(r == 1){
        if(n == 1) return 0;
        res += f(n-1, 1);
        res += f(n, 0)*x;
    }else{
        if(n == 1) return 1;
        res += f(n-1, 1);
        res += f(n-1, 0)*y;
    }
    return res;
}

int main(){
    ll n; cin >> n >> x >> y;
    cout << f(n, 1) << endl;

    
    return 0;
}