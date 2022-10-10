#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_dc

vector<ll> factorial(200005);
void init_factorial(){
    factorial[0] = factorial[1] = 1;
    rep(i, 2, 200005){
        factorial[i] = factorial[i-1]*i;
        factorial[i] %= MOD;
    }
}

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
    ll h, w; cin >> h >> w;
    init_factorial();

    ll ans = factorial[h+w-2];
    ll bunbo = (factorial[h-1]*factorial[w-1])%MOD;

    cout << (ans*bimpower(bunbo, MOD-2, MOD))%MOD << endl;
    
    return 0;
}