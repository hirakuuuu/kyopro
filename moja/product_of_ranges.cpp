#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://mojacoder.app/users/powell/problems/product_of_ranges

ll bp(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b&1) res = (res*a) % mod;
        a = (a*a) % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    int n, q; cin >> n >> q;
    vector<ll> a(n+1), b(n+1), ans;
    a[0] = 1;
    rep(i, 1, n+1) cin >> a[i];
    b[0] = 1;
    rep(i, 1, n+1) b[i] = (b[i-1]*a[i])%mod;

    while(q--){
        int l, r; cin >> l >> r;
        ans.push_back((b[r]*bp(b[l-1], mod-2)) % mod);
    }

    for(auto aa: ans){
        cout << aa << endl;
    }
    
    return 0;
}