#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc211/tasks/abc211_b

vector<string> S = {"H", "2B", "3B", "HR"};

int main(){
    vector<string> s(4);
    rep(i, 0, 4) cin >> s[i];
    sort(S.begin(), S.end());
    sort(s.begin(), s.end());
    if(S == s) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    
    return 0;
}