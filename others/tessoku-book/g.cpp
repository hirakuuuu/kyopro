#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_g

int main(){
    int d, n; cin >> d >> n;
    vector<int> ans(d+2);

    int l, r; 
    rep(i, 0, n){
        cin >> l >> r;
        ans[l]++;
        ans[r+1]--;
    }

    rep(i, 1, d+1){
        ans[i] += ans[i-1];
        cout << ans[i] << endl;
    }
    
    return 0;
}