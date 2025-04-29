#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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
    vector<ll> a(4);
    rep(i, 0, 4) cin >> a[i];
    ll n; cin >> n;
    vector<ll> t(4);
    rep(i, 0, 4) cin >> t[i];

    ll T; cin >> T;
    rep(x0, 0, a[0]+1){
        if(x0*t[0] > T || x0 > n) break;
        rep(x1, 0, a[1]+1){
            if(x0*t[0]+x1*t[1] > T || x0+x1 > n) break;
            ll rest = T-x0*t[0]-x1*t[1];
            ll rp = n-x0-x1;
            // cout << x1 << ' ' << x2 << endl;
            // x2*t[2]+x3*t[3] <= rest;
            if(t[2]-t[3] == 0){
                if(t[3]*rp != rest) continue;
                if(inr(0, n-x0-x1, a[3]+1)){
                    cout << x0 << ' ' << x1 << ' ' << 0 << ' ' << n-x0-x1 << endl;
                    return 0;
                }
                if(inr(0, n-x0-x1, a[2]+1)){
                    cout << x0 << ' ' << x1 << ' ' << n-x0-x1 << ' ' << 0 << endl;
                    return 0;
                }
                ll x2 = a[2];
                if(inr(0, n-x0-x1-x2, a[3]+1)){
                    cout << x0 << ' ' << x1 << ' ' << x2 << ' ' << n-x0-x1-x2 << endl;
                    return 0;
                }
                ll x3 = a[3];
                if(inr(0, n-x0-x1-x3, a[2]+1)){
                    cout << x0 << ' ' << x1 << ' ' << n-x0-x1-x3 << ' ' << x3 << endl;
                    return 0;
                }
            }else if(t[2]-t[3] > 0){
                if((rest-t[3]*rp) < 0) continue;
                if((rest-t[3]*rp)%(t[2]-t[3]) != 0) continue;
                ll x2 = (rest-t[3]*rp)/(t[2]-t[3]);
                if(inr(0, x2, a[2]+1) && inr(0, n-x0-x1-x2, a[3]+1)){
                    cout << x0 << ' ' << x1 << ' ' << x2 << ' ' << n-x0-x1-x2 << endl;
                    return 0;
                }
            }else{
                if((rest-t[3]*rp) > 0) continue;
                if((t[3]*rp-rest)%(t[3]-t[2]) != 0) continue;
                ll x2 = (t[3]*rp-rest)/(t[3]-t[2]);
                if(inr(0, x2, a[2]+1) && inr(0, n-x0-x1-x2, a[3]+1)){
                    cout << x0 << ' ' << x1 << ' ' << x2 << ' ' << n-x0-x1-x2 << endl;
                    return 0;
                }
            }
        }
    }


    return 0;
}