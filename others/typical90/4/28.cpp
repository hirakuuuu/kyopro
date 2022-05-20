#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_ab

/*
2次元いもす法
・各lx, ly, rx, ry に対して、a[lx][ly]++, a[rx][ry]++, a[lx][ry]--, a[rx][ly]--とする
・縦方向、横方向でそれぞれ累積和を取ると、各マス上に何枚の紙が重なっているかが求まる
*/


vector<vector<ll>> a(1005, vector<ll>(1005, 0));

int main(){
    int n; cin >> n;
    rep(i, 0, n){
        int lx, ly, rx, ry; cin >> lx >> ly >> rx >> ry;
        a[lx][ly]++;
        a[rx][ry]++;
        a[lx][ry]--;
        a[rx][ly]--;
    }

    rep(i, 0, 1001){
        rep(j, 1, 1001) a[i][j] += a[i][j-1];
    }
    rep(i, 1, 1001){
        rep(j, 0, 1001) a[i][j] += a[i-1][j];
    }

    vector<ll> ans(n+1, 0);
    rep(i, 0, 1001){
        rep(j, 0, 1001) ans[a[i][j]]++;
    }
    rep(i, 1, n+1){
        cout << ans[i] << endl;
    }

    
    return 0;
}