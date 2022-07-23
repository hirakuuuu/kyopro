#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc261/tasks/abc261_e

int main(){
    ll n, c; cin >> n >> c;
    vector<ll> t(n), a(n);
    rep(i, 0, n) cin >> t[i] >> a[i];

    vector<vector<ll>> b(n, vector<ll>(31));
    rep(i, 0, n){
        ll A = a[i];
        rep(j, 0, 31){
            b[i][j] = A%2;
            A /= 2;
        }
    }

    ll num0 = 0, num1 = 1;
    rep(i, 1, 31) num1 = 2*num1+1;

    vector<vector<ll>> ruiseki(n+1, vector<ll>(2));
    ruiseki[0][0] = num0;
    ruiseki[0][1] = num1;
    rep(i, 1, n+1){
        rep(j, 0, 31){
            if(t[i-1] == 1){
                ruiseki[i][0] = ruiseki[i-1][0]&a[i-1];
                ruiseki[i][1] = ruiseki[i-1][1]&a[i-1];
            }else if(t[i-1] == 2){
                ruiseki[i][0] = ruiseki[i-1][0]|a[i-1];
                ruiseki[i][1] = ruiseki[i-1][1]|a[i-1];
            }else{
                ruiseki[i][0] = ruiseki[i-1][0]^a[i-1];
                ruiseki[i][1] = ruiseki[i-1][1]^a[i-1];
            }
        }
    }

    ll x = c;
    
    rep(i, 1, n+1){
        ll X = x, ans = 0;
        rep(j, 0, 31){
            if(X&(1<<j)) ans += ruiseki[i][1]&(1<<j);
            else ans += ruiseki[i][0]&(1<<j);
        }
        cout << ans << "\n";
        x = ans;
    }



    
    return 0;
}