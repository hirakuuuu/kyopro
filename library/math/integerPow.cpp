#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 整数の累乗をやってくれるpow関数がほしい
// ただし、オーバーフローはエラーでる（そこは自己判断）

ll pow_int(ll n, ll x){
    ll res = 1LL;
    while(true){
        if(x%2 == 1) res = res*n;
        x /= 2;
        if(x == 0) break;
        n *= n;
    }
    return res;
}

int main(){
    int n, x; cin >> n >> x;
    cout << pow_int(n, x) << endl;
    return 0;
}