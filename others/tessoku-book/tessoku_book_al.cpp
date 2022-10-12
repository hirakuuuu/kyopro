#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_al

/*
 区間の上限値がn個指定されている場合の合計
 ・区間の左端の上限値を更新していく配列と区間の右端の上限値を更新していく配列を別で用意する
 ・左端からのは昇順に、右端からのは降順に累積和を取る
 ・2つの配列の内大きい方が上限値となる
*/

int main(){
    int d, n; cin >> d >> n;
    vector<int> l(n+1), r(n+1), h(n+1);
    rep(i, 1, n+1) cin >> l[i] >> r[i] >> h[i];

    vector<int> limit(d+1, 24);
    vector<int> re_limit(d+1, 24);
    rep(i, 1, n+1){
        limit[l[i]] = min(limit[l[i]], h[i]);
        re_limit[r[i]] = min(re_limit[r[i]], h[i]);
    }

    rep(i, 1, d+1){
        limit[i] = min(limit[i], limit[i-1]);
        re_limit[d-i] = min(re_limit[d-i], re_limit[d-i+1]);
    }

    ll ans = 0;
    rep(i, 1, d+1){
        ans += max(limit[i], re_limit[i]);
    }

    cout << ans << endl;
    
    return 0;
}