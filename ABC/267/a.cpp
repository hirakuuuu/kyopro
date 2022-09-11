#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc267/tasks/abc267_a

int main(){
    map<string, int> day;
    day["Monday"] = 1;
    day["Tuesday"] = 2;
    day["Wednesday"] = 3;
    day["Thursday"] = 4;
    day["Friday"] = 5;

    string s; cin >> s;
    cout <<  6-day[s] << endl;
    
    return 0;
}