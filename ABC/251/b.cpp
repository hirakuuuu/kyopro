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
    int n, w; cin >> n >> w;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> b(w+1);

    rep(i, 0, n){
        if(a[i] <= w) b[a[i]] = 1;
        rep(j, i+1, n){
            if(a[i]+a[j] <= w) b[a[i]+a[j]] = 1;
            rep(k, j+1, n){
                if(a[i]+a[j]+a[k] <= w) b[a[i]+a[j]+a[k]] = 1;
            }
        }
    }
    int ans = 0;
    rep(i, 1, w+1) ans += b[i];
    cout << ans << endl;
    
    return 0;
}