#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_ai

int main(){
    int n, q; cin >> n >> q;
    vector<ll> a(n+1), sum_a(n+1);
    rep(i, 1, n+1){
        cin >> a[i];
        sum_a[i] = sum_a[i-1]+a[i];
    }

    ll l, r; 

    while(q--){
        cin >> l >> r;
        printf("%lld\n", sum_a[r]-sum_a[l-1]);
    }
    
    return 0;
}