#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_l

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll l = 1, r = 1000000007;

    while(r-l > 0){
        ll m = (l+r)/2, cnt = 0;
        rep(i, 0, n){
            cnt += m/a[i];
        }

        if(cnt < k) l = m+1;
        else r = m;
    }

    cout << l << endl;
    
    return 0;
}