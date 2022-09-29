#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_al

int main(){
    int t, n; cin >> t >> n;
    vector<int> ans(t+1);

    int l, r;
    rep(i, 0, n){
        cin >> l >> r;
        ans[l]++;
        ans[r]--;
    }

    rep(i, 0, t){
        cout << ans[i] << '\n';
        ans[i+1] += ans[i];
    }
    
    return 0;
}