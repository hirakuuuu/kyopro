#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_aj

int main(){
    int n, k; cin >> n >> k;
    if(2*(n-1) <= k and k%2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}