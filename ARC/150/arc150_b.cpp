#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc150/tasks/arc150_b

int main() {
    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
        ll ans = max(a, b);

        rep(k, 1, sqrt(2*max(a, b))+1){
            // a+x = kの場合
            if(a <= k){
                ans = min(ans, k-a+(b+k-1)/k*k-b);
            }
            // z = kの場合
            if(b <= k*a){
                ans = min(ans, k*a-b);
            }else{
                ll bunbo = (b+k-1)/k;
                ans = min(ans, bunbo-a+bunbo*k-b);
            }
        }

        cout << ans << endl;

    }

    return 0;
}