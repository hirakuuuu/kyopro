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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;
    while(t--){
        ll n, x, k; cin >> n >> x >> k;
        if(k>118){
            cout << 0 << endl;
            continue;
        }

        ll h = 0, n_ = n;
        while(n_){
            h++;
            n_ >>= 1;
        }
        ll hx = 0, x_ = x;
        while(x_){
            hx++;
            x_ >>= 1;
        }

        ll ans = 0;
        if(h-hx >= k && (x<<k) <= n){
            ans += min(n+1, ((x+1)<<k))-(x<<k);
        }
        // cout << ans << endl;
        ll px = x, hx_ = hx, k_ = k;
        while(k && (x>>1) > 0){
            x >>= 1;
            hx--;
            k--;
            if(h-hx >= k && (x<<k) <= n){
                ans += min(n+1, ((x+1)<<k))-(x<<k);
            }
            // cout << hx << ' ' << ans << endl;
            ll tmp = k_-(hx_-hx)-1;
            if(tmp >= 0 && h-(hx+1) >= tmp && (px<<tmp) <= n){
                ans -= min(n+1, ((px+1)<<tmp))-(px<<tmp);
            }
            px = x;
            // cout << hx << ' ' << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}