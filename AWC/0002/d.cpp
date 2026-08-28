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
    int n, m; cin >> n >> m;
    vector<ll> c(n), r(m);
    rep(i, 0, n) cin >> c[i];
    rep(i, 0, m) cin >> r[i];

    sort(c.begin(), c.end());
    sort(r.begin(), r.end());
    ll ok = 0, ng = min(n, m)+1;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        bool f = true;
        // cout << mid << endl;
        rep(i, 0, mid){
            if(c[i] > r[m-1-(mid-1-i)]) f = false;
        }
        if(f) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}