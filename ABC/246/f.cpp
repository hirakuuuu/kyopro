#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc246/tasks/abc246_f

ll binpower(ll a, ll b){
    ll ans = 1;
    while(b > 0){
        if(b%2) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return ans;
}

int main(){
    ll n, l; cin >> n >> l;
    ll ans = 0;
    vector<vector<int>> s(n, vector<int>(26));
    rep(i, 0, n){
        string S; cin >> S;
        for(auto ss: S) s[i][ss-'a']++;
    }

    rep(i, 1, (1<<n)){
        vector<int> group(26, 1);
        int b = 0;
        rep(j, 0, n){
            if(i&(1<<j)){
                b++;
                rep(k, 0, 26){
                    group[k] &= s[j][k];
                }
            }
        }
        ll cnt = 0;
        rep(j, 0, 26) cnt += group[j];
        if(b%2) ans = (ans+binpower(cnt, l))%mod;
        else ans = (ans-binpower(cnt, l))%mod;
    }
    if(ans < 0) ans += mod;
    cout << ans << endl;
    return 0;
}