#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_dg

int main() {
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];

    vector<ll> g(n+1);
    rep(i, 1, n+1){
        ll m = a[i]%5;
        if(m == 0 or m == 1) g[i] = 0;
        if(m == 2 or m == 3) g[i] = 1;
        if(m == 4) g[i] = 2;
    }

    ll ans = 0;
    rep(i, 1, n+1){
        ans ^= g[i];
    }

    if(ans > 0) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}