#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc247/tasks/abc247_b

int main(){
    int n; cin >> n;
    vector<string> s(n), t(n);
    rep(i, 0, n) cin >> s[i] >> t[i];
    bool f1 = true, f2 = true;
    rep(i, 0, n){
        f1 = false, f2 = false;
        rep(j, 0, n){
            if(i != j and (s[i] == s[j] or s[i] == t[j])) f1 = true;
        }
        rep(j, 0, n){
            if(i != j and (t[i] == s[j] or t[i] == t[j])) f2 = true;
        }
        if(f1 and f2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;    
    return 0;
}