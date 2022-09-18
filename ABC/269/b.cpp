#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc269/tasks/abc269_b

int main(){
    vector<string> s(10);
    int a = 0, b = 0, c = 0, d = 0;
    rep(i, 0, 10){
        cin >> s[i];
    }

    bool f = false;

    rep(i, 0, 10){
        f = false;
        rep(j, 0, 10){
            if(s[i][j] == '#' and !f){
                c = j+1;
                d = j+1;
                f = true;
            }else if(s[i][j] == '#'){
                d = j+1;
            }
        }
    }

    rep(i, 0, 10){
        f = false;
        rep(j, 0, 10){
            if(s[j][i] == '#' and !f){
                a = j+1;
                b = j+1;
                f = true;
            }else if(s[j][i] == '#'){
                b = j+1;
            }
        }
    }
    cout << a << " " << b << "\n" << c << " " << d << endl;
    return 0;
}