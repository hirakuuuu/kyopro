
#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    ll k; cin >> k;
    ll x, y, z; cin >> x >> y >> z;
    int ans = 0;
    rep(i, 0, n){
        ll a, b, c; cin >> a >> b >> c;
        bool ok = false;
        rep(j, 0, 3){
            ll na = a-(x/3)*j;
            ll nb = b-(y/3)*j;
            ll nc = c-(z/3)*j;
            ll need = j;
            
            if(x > 0) need += (na+x-1)/x;
            else if(na > 0) need = k+1; 
            if(y > 0) need += (nb+y-1)/y;
            else if(nb > 0) need = k+1; 
            if(z > 0) need += (nc+z-1)/z;
            else if(nc > 0) need = k+1; 
            
            if(need <= k) ok = true;
        }
        if(ok) ans++;
    }
    cout << ans << endl;
    return 0;
}