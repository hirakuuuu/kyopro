#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc246/tasks/abc246_c

int main(){
    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int i = 0;
    while(i < n and k > 0){
        while(k > 0 and a[i] > x){
            a[i] -= x;
            k--;
        }
        i++;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll ans = 0;
    rep(j, 0, n){
        if(k > 0) k--;
        else ans += a[j];
    }
    cout << ans << endl;
    
    return 0;
}