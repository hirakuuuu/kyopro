#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_h

int h, w;
vector<vector<int>> x(1505, vector<int>(1505));
int q;

int calc_sum(int a, int b, int c, int d){
    return x[c][d]-x[a-1][d]-x[c][b-1]+x[a-1][b-1];
}

int main(){
    cin >> h >> w;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            cin >> x[i][j];
        }
    }

    rep(i, 1, h+1){
        rep(j, 1, w+1){
            x[i][j] += x[i-1][j]+x[i][j-1]-x[i-1][j-1];
        }
    }

    cin >> q;
    while(q--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << calc_sum(a, b, c, d) << endl;
    }

    return 0;
}