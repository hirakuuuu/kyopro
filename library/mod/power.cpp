#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 繰り返し二乗法
ll power(ll a, ll b, ll m=998244353){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return res;
}

int main(){

    return 0;
}