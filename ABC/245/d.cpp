#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc245/tasks/abc245_d

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n+1), b(m+1), c(n+m+1);
    rep(i, 0, n+1) cin >> a[i];
    rep(i, 0, n+m+1) cin >> c[i];
    
    for(int i = m; i >= 0; i--){
        int d = c[i+n]/a[n];
        rep(j, i, i+n){
            c[j] -= d*a[j-i];
        }
        b[i] = d;
    }

    rep(i, 0, m+1){
        if(i > 0) cout << " ";
        cout << b[i];
    }
    cout << endl;
    
    return 0;
}