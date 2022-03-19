#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

ll gcd(ll a, ll b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}


int main(){
    ll l, r; cin >> l >> r;
    ll ans = 0;
    int cnt = 0;
    while(cnt <= 100 and r > l){
        ll cpr = r, cpl = l;
        while(true){
            if(gcd(cpl, cpr) == 1) break;
            cpr--;
        }
        ll ans1 = cpr-cpl;
        cpr = r, cpl = l;
        while(true){
            if(gcd(cpl, cpr) == 1) break;
            cpl++;
        }
        ll ans2 = cpr-cpl;
        ans = max(ans, max(ans1, ans2));
        r--, l++;
        cnt++;
    }

    cout << ans << endl;
}