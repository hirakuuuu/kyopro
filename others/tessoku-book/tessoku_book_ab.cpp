#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ab

int main(){
    int n; cin >> n;
    int ans = 0;
    rep(i, 0, n){
        char t; cin >> t;
        int a; cin >> a;

        if(t == '+') ans = (ans+a)%10000;
        else if(t == '*') ans = (ans*a)%10000;
        else ans = (ans-a)%10000;

        if(ans < 0) ans += 10000;
        cout << ans << endl;
    }

    
    return 0;
}