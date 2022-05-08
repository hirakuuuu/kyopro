#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc250/tasks/abc250_b

int main(){
    int n, a, b; cin >> n >> a >> b;
    string s = "", t = "";
    rep(i, 0, n){
        rep(j, 0, b){
            if(i%2 == 0) s += '.';
            else s += '#';
            if(i%2) t += '.';
            else t += '#';
        }
    }
    rep(i, 0, n){
        rep(j, 0, a){
            if(i%2 == 0) cout << s << endl;
            else cout << t << endl;
        }
    }
    
    return 0;
}