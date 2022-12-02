#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc062/tasks/arc074_b

int main(){
    ll n; cin >> n;
    vector<ll> a(3*n);
    rep(i, 0, 3*n){
        cin >> a[i];
    }

    // 前半
    // i (n-1 <= i < 2*n) までの数字から n 個採用する場合の合計の最大値を取る
    vector<ll> l(n+1);
    priority_queue<ll, vector<ll>, greater<ll>> que_f;
    rep(i, 0, n){
        l[0] += a[i];
        que_f.push(a[i]);
    }
    ll total = l[0];
    ll del = 0;
    rep(i, 1, n+1){
        total += a[n+i-1];
        que_f.push(a[n+i-1]);
        del += que_f.top(); que_f.pop();
        l[i] += total-del;
    }

    // 後半
    // i (n <= i <= 2*n) からの数字から n 個採用する場合の合計の最小値を取る
    vector<ll> r(n+1);
    priority_queue<ll> que_l;
    rep(i, 0, n){
        r[n] += a[2*n+i];
        que_l.push(a[2*n+i]);
    }
    total = r[n];
    del = 0;
    rep(i, 1, n+1){
        total += a[2*n-i];
        que_l.push(a[2*n-i]);
        del += que_l.top(); que_l.pop();
        r[n-i] += total-del;
    }


    ll ans = -(1LL<<60);
    rep(i, 0, n+1){
        ans = max(ans, l[i]-r[i]);
    }

    cout << ans << endl;
    
    return 0;
}