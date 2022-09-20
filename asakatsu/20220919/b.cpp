#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc061/tasks/abc061_b

int main(){
    int n, m; cin >> n >> m;
    vector<int> cnt(n+1);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }

    rep(i, 1, n+1){
        cout << cnt[i] << endl;
    }

    return 0;
}