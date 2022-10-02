#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc271/tasks/abc271_b

int main(){
    int n, q; cin >> n >> q;
    vector<vector<int>> a(n);
    rep(i, 0, n){
        int l; cin >> l;
        rep(j, 0, l){
            int A; cin >> A;
            a[i].push_back(A);
        }
    }

    while(q--){
        int s, t; cin >> s >> t;
        cout << a[s-1][t-1] << "\n";
    }
    
    return 0;
}