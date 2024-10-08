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
    int n; cin >> n;
    ll m; cin >> m;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll ok = 0, ng = 1e18;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        ll tot = 0;
        rep(i, 0, n){
            tot += min(a[i], mid);
        }
        if(tot <= m) ok = mid;
        else ng = mid;
    }
    ll lim = 2e14+1;
    if(ok >= lim) cout << "infinite" << endl;
    else cout << ok << endl;
    
    
    return 0;
}