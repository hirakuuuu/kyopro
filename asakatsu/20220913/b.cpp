#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc251/tasks/abc251_b

int main(){
    ll n, w; cin >> n >> w;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<ll> good(w+1);

    ll ans = 0;

    rep(i, 0, n){
        if(a[i]<= w){
            good[a[i]] = 1;
        }
    }

    rep(i, 0, n){
        rep(j, i+1, n){
            if(a[i]+a[j] <= w){
                good[a[i]+a[j]] = 1;
            }
        }
    }

    rep(i, 0, n){
        rep(j, i+1, n){
            rep(k, j+1, n){
                if(a[i]+a[j]+a[k] <= w){
                    good[a[i]+a[j]+a[k]] = 1;
                }
            }
        }
    }
    
    rep(i, 0, w+1) ans += good[i];
    cout << ans << endl;

    
    return 0;
}