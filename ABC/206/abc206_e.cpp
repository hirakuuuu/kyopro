#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(ll i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc206/tasks/abc206_e

int main(){
    ll l, r; cin >> l >> r;
    ll ans = 0;

    vector<ll> erat(1000005);
    rep(i, 2, r+1){
        if(erat[i] != 0) continue;
        for(ll j = i; j <= r; j += i) erat[j]++;
        for(ll j = i*i; j <= r; j += i*i) erat[j] -= iinf;
    }

    rep(i, 2, r+1){
        if(erat[i] < 0) continue;
        ll cnt = (r/i)-((l-1)/i);
        if(erat[i]%2) ans += cnt*(cnt-1)/2;
        else ans -= cnt*(cnt-1)/2;
    }


    rep(i, max(2LL, l), r+1) ans -= r/i-1;
    cout << 2*ans << endl;
    
    return 0;
}