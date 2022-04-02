#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc246/tasks/abc246_d

int main(){
    ll n; cin >> n;
    ll a = 1, b = 0;
    while(b*b*b < n) b++;
    ll ans = b*b*b;
    while(a < b){
        while((a+b)*(a*a+b*b) >= n) b--;
        b++;
        if(ans-n > (a+b)*(a*a+b*b)-n) ans = (a+b)*(a*a+b*b);
        a++;
    }
    cout << ans << endl;
    return 0;
}