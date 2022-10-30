#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc247/tasks/abc247_a

int main(){
    string s; cin >> s;
    string t = "0";
    rep(i, 1, 4){
        if(s[i-1] == '1') t += "1";
        else t += "0";
    }
    cout << t << endl;
    
    return 0;
}