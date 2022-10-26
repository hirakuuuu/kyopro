#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_av

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n+1), b(n+1);

    rep(i, 1, n+1) cin >> a[i] >> b[i];
    priority_queue<int> que;
    rep(i, 1, n+1){
        que.push(b[i]);
        que.push(a[i]-b[i]);
    }

    ll ans = 0;
    rep(i, 0, k){
        int q = que.top(); que.pop();
        ans += q;
    }

    cout << ans << endl;

    
    return 0;
}