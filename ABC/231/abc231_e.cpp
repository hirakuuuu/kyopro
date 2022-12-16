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
// https://atcoder.jp/contests/abc231/tasks/abc231_e

vector<ll> a(105);
map<pll, ll> m;

// i番目までの硬貨でx円を支払うためのおつりも含めた最小枚数
ll f(ll x, ll i){
    if(m[{x, i}] > 0) return m[{x, i}];
    if(a[i+1] == 0) return m[{x, i}] = x/a[i];
    ll l = x-x%a[i+1];
    return m[{x, i}] = min((x%a[i+1])/a[i]+f(l, i+1), (a[i+1]-x%a[i+1])/a[i]+f(l+a[i+1], i+1));
}

int main(){
    ll n, x; cin >> n >> x;
    rep(i, 0, n) cin >> a[i];

    ll ans = f(x, 0);

    cout << ans << endl;



    
    return 0;
}