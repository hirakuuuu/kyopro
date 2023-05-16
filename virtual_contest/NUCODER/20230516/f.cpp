#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll f(ll a, ll b){
    return a*a*a+a*a*b+a*b*b+b*b*b;
}

int main(){
    ll n; cin >> n;
    ll ans = (1LL<<60);
    rep(a, 0, 1000005){
        ll l = 0, r = 1000000;
        while(r-l > 0){
            ll m = (l+r)/2;
            if(n <= f(a, m)) r = m;
            else l = m+1;
        }
        chmin(ans, f(a, l));
    }
    cout << ans << endl;

    
    return 0;
}