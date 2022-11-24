#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc013/tasks/abc013_3

int main(){
    ll n, h; cin >> n >> h;
    ll a, b, c, d, e; cin >> a >> b >> c >> d >> e;

    ll ans = c*n;

    // 普通の食事をi回取る
    rep(i, 0, n+1){
        ll rest = h+b*i;
        ll j = 0;
        if(e*(n-i)-rest >= 0) j = (e*(n-i)-rest)/(d+e)+1;
        if(i+j > n) continue;
        ans = min(ans, a*i+c*j);
    }

    // 質素な食事をi回取る
    rep(i, 0, n+1){
        ll rest = h+d*i;
        ll j = 0;
        if(e*(n-i)-rest >= 0) j = (e*(n-i)-rest)/(b+e)+1;
        if(i+j > n) continue;
        ans = min(ans, c*i+a*j);
    }

    cout << ans << endl;
    
    return 0;
}