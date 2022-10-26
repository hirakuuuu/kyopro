#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_as

int main(){
    int n; cin >> n;
    char c; cin >> c;
    string s; cin >> s;
    int total = 0;
    string color = "WRB";
    map<char, int> m;
    rep(i, 0, 3) m[color[i]] = i;
    rep(i, 0, n) total += m[s[i]];

    if(c == color[total%3]) cout << "Yes" << endl;
    else cout << "No" << endl;

    
    return 0;
}