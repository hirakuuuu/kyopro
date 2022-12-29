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

// 問題
// https://atcoder.jp/contests/abc247/tasks/abc247_e

int main(){
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<int> pos_x(n), pos_y(n), pos_ex(n), pos_ey(n);
    int px = n, py = n, pex = n, pey = n;
    rep(i, 0, n){
        if(a[n-i-1] == x) px = n-i-1;
        if(a[n-i-1] == y) py = n-i-1;
        if(a[n-i-1] > x) pex = n-i-1;
        if(a[n-i-1] < y) pey = n-i-1;

        pos_x[n-i-1] = px;
        pos_y[n-i-1] = py;
        pos_ex[n-i-1] = pex;
        pos_ey[n-i-1] = pey;
    }

    ll ans = 0;
    rep(i, 0, n){
        int l = max(pos_x[i], pos_y[i]);
        int r = min(pos_ex[i], pos_ey[i]);
        ans += max(0, r-l);
    }
    cout << ans << endl;
    
    return 0;
}