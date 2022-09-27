#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cc

int main(){
    string s; cin >> s;
    int ans = 0;

    rep(i, 0, s.size()){
        if(s[i] == '1'){
            ans += (1<<(s.size()-i-1));
        }
    }

    cout << ans << endl;
    
    return 0;
}