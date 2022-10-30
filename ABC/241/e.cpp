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
    ll k; cin >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll ans = 0;
    ll x = 0;
    vector<ll> s(n+5);
    s[0] = 0;
    vector<ll> pos(n);
    ll cnt = 1;
    while(k){
        ans += a[x];
        s[cnt] = s[cnt-1]+a[x];
        k--;
        if(pos[ans%n]){
            break;
        }
        pos[ans%n] = cnt;
        x = ans%n;
        cnt++;
    }
    // kがすでに0である場合
    if(k == 0){
        cout << ans << endl;
        return 0;
    }
    ll cp_ans = ans;
    ll roop = s[cnt]-s[pos[cp_ans%n]];
    ll sho = k/(cnt-pos[cp_ans%n]);
    ll rest = k%(cnt-pos[cp_ans%n]);
    ans += sho*roop+(s[pos[cp_ans%n]+rest]-s[pos[cp_ans%n]]);
    cout << ans << endl;
}