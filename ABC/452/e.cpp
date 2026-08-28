#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    

    vector<mint> acc_a(n+1);
    rep(i, 0, n){
        acc_a[i+1] = acc_a[i]+a[i];
    }
    mint sum_b = 0;
    rep(i, 0, m){
        sum_b += b[i];
    }

    mint ans = 0;
    rep(i, 0, n){
        ans += mint(a[i])*(i+1)*sum_b;
    }

    for(ll j = 1; j <= m; j++){
        for(ll k = 1; k <= n/j; k++){
            ll l = k*j;
            ll r = min((ll)n+1, (k+1)*j);
            // cout << j << ' ' << k << ' ' << l << ' ' << r << endl;
            ans -= (acc_a[r-1]-acc_a[l-1])*k*j*b[j-1];
        }
    }
    cout << ans.val() << endl;
    return 0;
}