#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc270/tasks/abc270_b

int main(){
    int x, y, z; cin >> x >> y >> z;
    if(x < 0){
        x *= -1;
        y *= -1;
        z *= -1;
    }

    int ans = 0;

    if(y < 0 or x < y){
        ans = x;
    }else{
        if(y < z){
            ans = -1;
        }else{
            if(0 < z) ans = x;
            else ans = 2*(-z)+x;
        }
    }
    cout << ans << endl;

    
    return 0;
}