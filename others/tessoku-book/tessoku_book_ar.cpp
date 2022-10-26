#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ar

int main(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);

    int f = 0;

    while(q--){
        int t; cin >> t;
        if(t == 1) {
            int x, y; cin >> x >> y;
            if(f == 0) a[x-1] = y;
            else a[n-x] = y;
        }else if(t == 2) {
            f = 1-f;
        }else {
            int x; cin >> x;
            if(f == 0) cout << a[x-1] << "\n";
            else cout << a[n-x] << "\n";
        }
    }
    
    return 0;
}