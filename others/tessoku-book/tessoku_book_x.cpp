#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_x

int a[100005], v[100005];

int main(){
    int n; cin >> n;
    rep(i, 1, n+1) cin >> a[i];
    rep(i, 0, n+1) v[i] = 1e9;

    int len = 0;
    rep(i, 1, n+1){
        int pos = lower_bound(v, v+len, a[i])-v;
        v[pos] = a[i];
        if(pos == len) len++;
    }

    cout << len << endl;
    
    return 0;
}