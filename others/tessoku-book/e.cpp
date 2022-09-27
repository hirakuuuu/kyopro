#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_e

int main(){
    int n, k; cin >> n >> k;
    int ans = 0;

    rep(red, 1, n+1){
        rep(blue, 1, n+1){
            int white = k-(red+blue);
            if(1 <= white and white <= n) ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}