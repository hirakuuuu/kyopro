#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc253/tasks/abc253_a

int main(){
    int a, b, c; cin >> a >> b >> c;
    vector<int> abc = {a, b, c};
    sort(abc.begin(), abc.end());
    if(abc[1] == b) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}