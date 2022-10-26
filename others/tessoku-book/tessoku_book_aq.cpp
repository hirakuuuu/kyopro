#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_aq

int main(){
    int n, l; cin >> n >> l;
    int ans = 0;
    rep(i, 0, n){
        int a; cin >> a;
        char b; cin >> b;
        if(b == 'W') ans = max(ans, a);
        else ans = max(ans, l-a);
    }

    cout << ans << endl;
    
    return 0;
}