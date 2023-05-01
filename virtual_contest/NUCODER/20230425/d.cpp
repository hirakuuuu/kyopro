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
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll ans = -(1LL<<60);

    chmax(ans, a*c);
    chmax(ans, b*c);
    chmax(ans, a*d);
    chmax(ans, b*d);

    cout << ans << endl;
    
    return 0;
}