#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc264/tasks/abc264_b

int main(){
    int r, c; cin >> r >> c;

    rep(i, 1, 9){
        if(r == i or c == i or r == 16-i or c == 16-i){
            if(i%2) cout << "black" << endl;
            else cout << "white" << endl;
            return 0;
        }
    }
    
    return 0;
}