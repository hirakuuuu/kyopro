#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0, cnt = 2;
    rep(i, 0, n-1){
        ans += a[i]*cnt;
        cnt++;
    }
    ans += a[n-1]*n;
    cout << ans << endl;
    return 0;
}