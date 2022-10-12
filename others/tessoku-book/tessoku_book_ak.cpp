#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ak

int main(){
    ll n, m, b; cin >> n >> m >> b;
    ll a = 0, c = 0;
    rep(i, 0, n){
        ll A; cin >> A; a += A;
    }
    rep(i, 0, m){
        ll C; cin >> C; c += C;
    }

    cout << a*m+c*n+b*n*m << endl;

    
    return 0;
}