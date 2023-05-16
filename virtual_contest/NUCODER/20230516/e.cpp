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

int main(){
    ll n, m; cin >> n >> m;
    ll ans = (1LL<<60);
    rep(a, 1, min(n+1, 1000005LL)){
        ll b = (m+a-1)/a;
        if(a<= b and b <= n) chmin(ans, a*b);
    }
    if(ans == (1LL<<60)) cout << -1 << endl;
    else cout << ans << endl;


    
    return 0;
}