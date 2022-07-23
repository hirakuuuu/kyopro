#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc261/tasks/abc261_b

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            char c; cin >> c;
            if(c == 'W') a[i][j] = 1;
            else if(c == 'L') a[i][j] = -1;
        }
    }

    rep(i, 0, n){
        rep(j, 0, n){
            if(a[i][j]+a[j][i] != 0){
                cout << "incorrect" << endl;
                return 0;
            }
        }
    }
    cout << "correct" << endl;
    
    return 0;
}