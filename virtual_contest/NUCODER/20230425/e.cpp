#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<ll> a(n+1);
    rep(i, 1, n+1) cin >> a[i];
    vector<ll> s(n+1);
    rep(i, 1, n+1){
        s[i] = s[i-1]+a[i];
        s[i] %= MOD;
    }

    ll ans = 0;
    rep(i, 1, n+1){
        ans += a[i]*(s[n]-s[i]+MOD);
        ans %= MOD;
    } 
    cout << ans << endl;
    
    return 0;
}