#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc279/tasks/abc279_b

int main(){
    string s, t; cin >> s >> t;
    bool f = false;
    if(s.size() < t.size()){
        cout << "No" << endl;
        return 0;
    }

    rep(i, 0, s.size()-t.size()+1){
        bool f1 = true;
        rep(j, i, i+t.size()){
            if(j >= s.size()){
                f1 = false;
                break;
            }else{
                f1 &= (t[j-i] == s[j]);
            }
        }
        f |= f1;
    }

    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}