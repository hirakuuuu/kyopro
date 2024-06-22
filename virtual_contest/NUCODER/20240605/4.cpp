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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    rep(i, 0, n) cin >> x[i] >> y[i] >> z[i];
    ll ans = 0;
    rep(i, 0, 2) rep(j, 0, 2) rep(k, 0, 2){
        vector<ll> X(n), Y(n), Z(n);
        rep(l, 0, n){
            if(i == 0) X[l] = x[l];
            else X[l] = -x[l];
        }
        rep(l, 0, n){
            if(j == 0) Y[l] = y[l];
            else Y[l] = -y[l];
        }
        rep(l, 0, n){
            if(k == 0) Z[l] = z[l];
            else Z[l] = -z[l];
        }

        vector<ll> c(n);
        rep(l, 0, n) c[l] = X[l]+Y[l]+Z[l];
        sort(c.rbegin(), c.rend());
        ll tmp = 0;
        rep(l, 0, m) tmp += c[l];
        chmax(ans, tmp);
    }
    cout << ans << endl;
    
    return 0;
}