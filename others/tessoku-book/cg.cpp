#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cg

vector<vector<int>> sum_p(1505, vector<int>(1505));

int calc_sum(int a, int b, int c, int d){
    return sum_p[c][d]-sum_p[a-1][d]-sum_p[c][b-1]+sum_p[a-1][b-1];
}

int main(){
    int n; cin >> n;

    int x, y;
    rep(i, 0, n){
        cin >> x >> y;
        sum_p[x][y]++;
    }

    rep(i, 1, 1505){
        rep(j, 1, 1505){
            sum_p[i][j] += sum_p[i][j-1];
        }
    }

    rep(i, 1, 1505){
        rep(j, 1, 1505){
            sum_p[i][j] += sum_p[i-1][j];
        }
    }

    int q; cin >> q;
    while(q--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << calc_sum(a, b, c, d) << '\n';
    }
    
    
    return 0;
}