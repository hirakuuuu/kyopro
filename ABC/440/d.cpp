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
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    while(q--){
        ll x, y; cin >> x >> y;
        ll ng = x-1, ok = INF;
        while((ok-ng) > 1){
            ll mid = (ok+ng)/2;
            ll l = (lower_bound(a.begin(), a.end(), x)-a.begin());
            ll r = (upper_bound(a.begin(), a.end(), mid)-a.begin());
            // cout << mid-x+1-(r-l) << ' ' << y << ' ' << mid << endl;
            if(mid-x+1-(r-l) >= y) ok = mid;
            else ng = mid;
        }
        cout << ok << endl;
    }
    return 0;
}