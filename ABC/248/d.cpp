#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc248/tasks/abc248_d

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    vector<vector<int>> num(200005);
    rep(i, 0, n){
        num[a[i]].push_back(i+1);
    }

    int q; cin >> q;
    while(q--){
        int l, r, x; cin >> l >> r >> x;
        auto itr_L = lower_bound(num[x].begin(), num[x].end(), l);
        auto itr_R = upper_bound(num[x].begin(), num[x].end(), r);
        cout << itr_R-itr_L << endl;
    }
    return 0;
}