#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc265/tasks/abc265_b

int main(){
    ll n, m, t; cin >> n >> m >> t;
    vector<ll> a(n-1), y(n);
    rep(i, 0, n-1) cin >> a[i];
    rep(i, 0, m){
        int x; cin >> x;
        cin >> y[x-1];
    }

    rep(i, 0, n-1){
        if(t <= a[i]){
            cout << "No" << endl;
            return 0;
        }
        t -= a[i];
        t += y[i+1];
    }

    cout << "Yes" << endl;
    
    return 0;
}