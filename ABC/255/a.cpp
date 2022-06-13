#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc255/tasks/abc255_a

int main(){
    int r, c; cin >> r >> c;
    vector<vector<int>> a(2, vector<int>(2));
    rep(i, 0, 2){
        rep(j, 0, 2) cin >> a[i][j];
    }
    cout << a[r-1][c-1] << endl;
    
    return 0;
}