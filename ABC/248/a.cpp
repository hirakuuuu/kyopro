#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc248/tasks/abc248_a

int main(){
    string s; cin >> s;
    vector<int> t(10);
    rep(i, 0, 9){
        t[s[i]-'0'] = 1;
    }
    rep(i, 0, 10){
        if(!t[i]){
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}