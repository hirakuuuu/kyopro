#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/agc024/tasks/agc024_c

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll ans = 0;
    ll tmp = 0;
    for(int i = n-1; i >= 0; i--){
        if(a[i] <= i and tmp <= a[i]){
            if(tmp < a[i]) ans += a[i];
            tmp = a[i]-1;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    
    return 0;
}