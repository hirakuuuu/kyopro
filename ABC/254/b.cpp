#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc254/tasks/abc254_b

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    a[0][0] = 1;
    cout << a[0][0] << endl;
    rep(i, 1, n){
        a[i][0] = 1;
        cout << a[i][0] << " ";
        rep(j, 1, i){
            a[i][j] = a[i-1][j-1]+a[i-1][j];
            cout << a[i][j] << " ";
        }
        a[i][i] = 1;
        cout << a[i][i] << endl;
    }
    
    return 0;
}