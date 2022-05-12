#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_n


/*
差が最小になる組み合わせ　→　昇順ソートして順番に合わせる
・2つの組で考えると分かりやすい
・順番を無視して当てはめると、交差する部分が出てきて、距離が長くなることが分かる
*/


int main(){
    int n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;
    rep(i, 0, n){
        ans += abs(a[i]-b[i]);
    }
    cout << ans << endl;
    
    return 0;
}