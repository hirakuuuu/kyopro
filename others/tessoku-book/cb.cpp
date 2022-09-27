#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cb

int n, a[105];
bool exist_sum_1000 = false;

int main(){
    cin >> n;
    rep(i, 0, n) cin >> a[i];

    rep(i, 0, n){
        rep(j, i+1, n){
            rep(k, j+1, n){
                exist_sum_1000 |= a[i]+a[j]+a[k] == 1000;
            }
        }
    }

    if(exist_sum_1000) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}