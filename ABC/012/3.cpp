#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc012/tasks/abc012_3

int main(){
    int n; cin >> n;
    int s = 0;
    rep(i, 1, 10){
        rep(j, 1, 10) s += i*j;
    }

    rep(i, 1, 10){
        rep(j, 1, 10){
            if(i*j == s-n){
                cout << i  << " x " << j << endl;
            }
        }
    }
    
    return 0;
}