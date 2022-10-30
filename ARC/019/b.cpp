#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc019/tasks/arc019_2

int main(){
    string s; cin >> s;
    int n = s.size(), cnt = 0;
    rep(i, 0, n/2+n%2) cnt += (s[i] == s[n-i-1]);
    if(n/2+n%2-cnt >= 2) cout << n*25 << endl;
    else if(n/2+n%2-cnt == 1) cout << (n-2)*25+2*24 << endl;
    else cout << (n-n%2)*25 << endl;
    return 0;
}