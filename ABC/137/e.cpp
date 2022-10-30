#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc137/tasks/abc137_e

int n, m, p;
vector<vector<int>> e;
vector<ll> a(5005), b(5005), c(5005), d(2505, -(1LL<<60));

void bf(){
    d[0] = 0;
    rep(i, 0, n+n){
        rep(j, 0, m){
            if(d[a[j]] != -1LL<<60 and d[a[j]]+c[j] > d[b[j]]){
                d[b[j]] = d[a[j]]+c[j];
                if (i >= n-1) d[b[j]] = 1LL<<60;
            }
        }
    }
}

int main(){
    cin >> n >> m >> p;
    rep(i, 0, m){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        c[i] -= p;
    }
    bf();
    if(d[n-1] >= 1LL<<60) cout << -1 << endl;
    else cout << max(0LL, d[n-1]) << endl;
    return 0;
}