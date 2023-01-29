#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
// 問題
// https://atcoder.jp/contests/abc048/tasks/arc064_a


int main(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll ans = 0;
    rep(i, 0, n) {
        ans += max(0LL, a[i]-x);
        a[i] = min(a[i], x);
    }

    rep(i, 1, n){
        ans += max(0LL, (a[i-1]+a[i])-x);
        a[i] -= max(0LL, (a[i-1]+a[i])-x);
    }
    cout << ans << endl;

    
    return 0;
}