#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc247/tasks/abc247_e

int main(){
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    set<int> px, py, mx, my;
    rep(i, 0, n){
        if(a[i] == x) px.insert(i);
        if(a[i] == y) py.insert(i);
        if(x < a[i]) mx.insert(i);
        if(a[i] < y) my.insert(i);
    }
    px.insert(n);
    py.insert(n);
    mx.insert(n);
    my.insert(n);
    ll ans = 0;
    rep(i, 0, n){
        int sx = *px.lower_bound(i);
        int sy = *py.lower_bound(i);
        int tx = *mx.lower_bound(i);
        int ty = *my.lower_bound(i);

        int s = max(sx, sy);
        int t = min(tx, ty);

        ans += max(0, t-s);
    }
    cout << ans << endl;

    
    return 0;
}