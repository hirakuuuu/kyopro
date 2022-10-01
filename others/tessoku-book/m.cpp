#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_m

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll ans = 0, l = 0, r = 1;
    while(l < n){
        while(r < n and a[r]-a[l] <= k) r++;
        ans += r-l-1;
        l++;
    }

    cout << ans << endl;
    
    return 0;
}