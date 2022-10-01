#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_k

int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    int l = 0, r = n;
    while(r-l > 1){
        int m = (l+r)/2;
        if(a[m] <= x) l = m;
        else r = m;
    }

    cout << l+1 << endl;
    
    return 0;
}