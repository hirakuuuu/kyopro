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
    ll x; cin >> x;

    vector<ll> u(n), d(n);
    rep(i, 0, n) cin >> u[i] >> d[i];

    ll ok = 0, ng = INF;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        // 葉の長さを mid にそろえることができるか
        bool f = true;
        ll l = -1, r = -1;
        rep(i, 0, n){
            if(u[i]+d[i] < mid){
                f = false;
                break;
            }
            if(i == 0){
                l = max(0LL, mid-d[i]);
                r = min(u[i], mid);
            }else{
                l = max({0LL, l-x, mid-d[i]});
                r = min({u[i], r+x, mid});
            }
            if(l > r){
                f = false;
                break;
            }
        }
        if(f) ok = mid;
        else ng = mid;
    }

    ll ans = 0;
    rep(i, 0, n){
        ans += (u[i]+d[i])-ok;
    }
    cout << ans << endl;

    
    return 0;
}