#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cl

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n), lim_r(n);
    rep(i, 0, n) cin >> a[i];

    ll ans = 0, r = 0, total = 0;
    rep(l, 0, n){
        if(l == 0) r = 0;
        else r = max((ll)l, lim_r[l-1]);
        while(r < n and total+a[r] <= k){
            total += a[r];
            r++;
        }

        ans += r-l;
        if(r-l > 0) total -= a[l];
        lim_r[l] = r;
    }

    cout << ans << endl;


    
    return 0;
}