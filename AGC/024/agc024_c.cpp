#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/agc024/tasks/agc024_c

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    pll tail = {0, n};
    ll ans = 0;
    for(int i = n-1; i >= 0; i--){
        if(tail.first-(tail.second-i) > a[i]){
            cout << -1 << endl;
            return 0;
        }
        if(tail.first-(tail.second-i) < a[i]){
            if(a[i] > i){
                cout << -1 << endl;
                return 0;
            }else{
                ans += a[i];
                tail = {a[i], i};
            }
        }
    }

    cout << ans << endl;

    
    return 0;
}