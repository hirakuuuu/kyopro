#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_v

/*
最大公約数を求める　→　ユークリッド
*/

ll gcd(ll a, ll b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

int main(){
    ll a, b, c; cin >> a >> b >> c;
    ll d = gcd(a, gcd(b, c));
    cout << (a/d-1)+(b/d-1)+(c/d-1) << endl;
    
    return 0;
}