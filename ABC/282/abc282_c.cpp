#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc282/tasks/abc282_c

int main(){
    int n; cin >> n;
    string s; cin >> s;
    bool f = true;
    rep(i, 0, n){
        if(s[i] == '"'){
            f = !f;
        }else{
            if(f and s[i] == ',') s[i] = '.';
        }
    }
    cout << s << endl;
    
    return 0;
}