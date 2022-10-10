#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_df

int main(){
    int n, h, w; cin >> n >> h >> w;

    vector<int> a(n+1), b(n+1);
    rep(i, 1, n+1) cin >> a[i] >> b[i];

    int ans = 0;
    rep(i, 1, n+1){
        ans ^= a[i]-1;
        ans ^= b[i]-1;
    }

    if(ans > 0) cout << "First" << endl;
    else cout << "Second" << endl;

    
    return 0;
}