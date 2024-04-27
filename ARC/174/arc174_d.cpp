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
    int t; cin >> t;
    vector<ll> ten(19, 1);
    rep(i, 1, 19) ten[i] = ten[i-1]*10;
    while(t--){
        ll n; cin >> n;
        int order = 0;
        ll n_ = n;
        while(n_){
            order++;
            n_ /= 10;
        }
        ll ans = 0;
        rep(i, 0, order){
            if(i%2 == 0){
                // z = 10^(i/2)... となる数字
                ll l = ten[i];
                ll r = min(n+1, ten[i]+ten[i/2]);
                ans += r-l;
            }else{
                // 999...98...が1個、999...99... が全部
                if(ten[i+1]-2LL*ten[(i+1)/2] <= n) ans++;
                ll l = ten[i+1]-ten[(i+1)/2];
                ll r = min(n+1, ten[i+1]);
                if(r < l) continue;
                ans += r-l;
            }
            // cout << ans << endl;

        }
        cout << ans << '\n';
    }

    // ll n = 1e3, cnt = 0;
    // rep(i, 1, n+1){
    //     string x = to_string(i);
    //     string y = to_string((int)sqrt(i));
    //     if(x.substr(0, y.size()) == y){
    //         cnt++;
    //     }
    // }
    // cout << cnt << endl;
    
    return 0;
}