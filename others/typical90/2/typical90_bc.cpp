#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_bc

int main(){
    ll n, p, q; cin >> n >> p >> q;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll ans = 0;
    rep(i, 0, n){
        rep(j, i+1, n){
            rep(k, j+1, n){
                rep(l, k+1, n){
                    rep(m, l+1, n){
                        ll tmp = 1;
                        tmp *= a[i];
                        tmp %= p;
                        tmp *= a[j];
                        tmp %= p;
                        tmp *= a[k];
                        tmp %= p;
                        tmp *= a[l];
                        tmp %= p;
                        tmp *= a[m];
                        tmp %= p;
                        if(tmp == q) ans++;
                    }
                }
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}