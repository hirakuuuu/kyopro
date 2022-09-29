#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ce

int main(){
    int n; cin >> n;
    vector<int> a(n+1), sum_a(n+1);
    rep(i, 1, n+1){
        cin >> a[i];
        sum_a[i] = sum_a[i-1]+a[i];
    }

    int q, l, r; cin >> q;
    int win, lose;
    while(q--){
        cin >> l >> r;
        win = sum_a[r]-sum_a[l];
        lose = (r-l+1)-win;

        if(win > lose) cout << "win" << endl;
        else if(win == lose) cout << "draw" << endl;
        else cout << "lose" << endl;
    }
    
    return 0;
}