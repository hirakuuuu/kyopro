#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc221/tasks/abc221_d

int main(){
    int n; cin >> n;

    vector<pll> change;
    rep(i, 0, n){
        ll a, b; cin >> a >> b;
        change.push_back({a, 1});
        change.push_back({a+b, -1});
    }

    sort(change.begin(), change.end());

    ll cnt = 0;
    vector<ll> ans(n+1);

    rep(i, 0, 2*n-1){
        cnt += change[i].second;
        ans[cnt] += change[i+1].first-change[i].first;
    }

    rep(i, 1, n+1){
        if(i > 1) cout << ' ';
        cout << ans[i];
    }
    cout << endl;

    return 0;
}