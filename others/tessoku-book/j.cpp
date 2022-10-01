#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_j

int n, d;
vector<int> a(100005), max_l(100005), max_r(100005);

int main(){
    cin >> n;
    rep(i, 1, n+1){
        cin >> a[i];
    }

    rep(i, 1, n+1){
        max_l[i] = max(max_l[i-1], a[i]);
    }
    rep(i, 0, n){
        max_r[n-i] = max(max_r[n-i+1], a[n-i]);
    }

    cin >> d;
    int l, r;
    while(d--){
        cin >> l >> r;
        cout << max(max_l[l-1], max_r[r+1]) << '\n';
    }
    
    return 0;
}