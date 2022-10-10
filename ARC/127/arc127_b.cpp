#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc127/tasks/arc127_b

int main(){
    ll n, l; cin >> n >> l;
    ll len = 0, _ = n-1;
    while(_ > 0){
        len++;
        _ /= 3;
    }

    vector<string> s(3*n);
    rep(i, 0, n){
        s[i] += '0';
        rep(j, 1, l-len) s[i] += '2';
    }
    rep(i, 0, n){
        s[i+n] += '1';
        rep(j, 1, l-len) s[i+n] += '1';
    }
    rep(i, 0, n){
        s[i+2*n] += '2';
        rep(j, 1, l-len) s[i+2*n] += '0';
    }

    string add_char = "012";

    rep(i, 0, n){
        int j = i;
        vector<string> t(3);
        rep(k, 0, len){
            t[0] = add_char[(j+2)%3]+t[0];
            t[1] = add_char[(j+1)%3]+t[1];
            t[2] = add_char[j%3]+t[2];
            j /= 3;
        }
        s[i] += t[0];
        s[i+n] += t[1];
        s[i+2*n] += t[2];
    }

    rep(i, 0, 3*n) cout << s[i] << "\n";
    

    
    return 0;
}