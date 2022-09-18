#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc226/tasks/abc226_c

int main(){
    ll n; cin >> n;
    vector<ll> t(n), k(n);
    vector<vector<ll>> a(n);
    rep(i, 0, n){
        cin >> t[i] >> k[i];
        rep(j, 0, k[i]){
            ll A; cin >> A;
            a[i].push_back(A-1);
        }
    }

    vector<bool> need(n);
    need[n-1] = true;
    queue<ll> que;
    rep(i, 0, k[n-1]){
        que.push(a[n-1][i]);
        need[a[n-1][i]] = true;
    }

    while(!que.empty()){
        ll q = que.front(); que.pop();
        for(auto nq: a[q]){
            if(need[nq]) continue;
            need[nq] = true;
            que.push(nq);
        }
    }

    ll ans = 0;

    rep(i, 0, n){
        if(need[i]) ans += t[i];
    }

    cout << ans << endl;

    return 0;
}