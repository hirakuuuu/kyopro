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
// https://atcoder.jp/contests/abc037/tasks/abc037_c

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<ll> acc_a(n+1);
    rep(i, 0, n){
        acc_a[i+1] = acc_a[i]+a[i];
    }

    ll ans = 0;
    rep(i, 0, n-k+1){
        ans += acc_a[i+k]-acc_a[i];
    }
    cout << ans << endl;
    
    return 0;
}