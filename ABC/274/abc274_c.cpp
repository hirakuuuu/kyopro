#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc274/tasks/abc274_c

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<int> ans(2*n+2);
    rep(i, 0, n){
        ans[2*(i+1)] = ans[a[i]]+1;
        ans[2*(i+1)+1] = ans[a[i]]+1;
    }

    rep(i, 1, 2*n+2){
        cout << ans[i] << "\n";
    }
    
    return 0;
}