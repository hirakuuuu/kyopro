#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/agc057/tasks/agc057_b

int main(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    ll max_a = 0;
    ll min_a = 1LL<<60;
    rep(i, 0, n){
        cin >> a[i];
        min_a = min(min_a, a[i]);
        max_a = max(max_a, a[i]);
    }
    vector<pll> b(n);

    rep(i, 0, n){
        ll l = a[i];
        ll r = a[i];
        while(2*r+x < max_a){
            l *= 2;
            r = 2*r+x;
        }
        l *= 2;
        if(l <= max_a) b[i] = {max_a, max_a};
        else b[i] = {r, l};
    }

    sort(b.begin(), b.end());
    ll ans = 1LL<<60, max_r = max_a;
    rep(i, 0, n){
        ans = min(ans, max_r-b[i].first);
        max_r = max(max_r, b[i].second);
    }

    if(ans < x) cout << 0 << endl;
    else cout << ans << endl;
    
    return 0;
}