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
    ll n, m; cin >> n >> m;
    vector<ll> p(n);
    rep(i, 0, n) cin >> p[i];

    // ok 円以下の商品をすべて買っても m 円以下
    ll ok = 0, ng = m+1;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        ll sum = 0;
        bool f = true;
        rep(i, 0, n){
            ll mx = mid/p[i];
            if(mx == 0) continue;
            if(mx%2 == 0) mx--;
            mx = (mx+1)/2;
            if(mx > 1e9 || m/(mx*mx) < p[i]){
                f = false;
                break;
            }
            if(sum+mx*mx*p[i] > m){
                f = false;
                break;
            }
            sum += mx*mx*p[i];
        }
        if(f && sum <= m) ok = mid;
        else ng = mid;
    }

    // ok 円以下の商品は全部買う
    // ok+1 円の商品はあれば買えるだけ買う
    ll sum = 0, ans = 0;
    rep(i, 0, n){
        ll mx = ok/p[i];
        if(mx == 0) continue;
        if(mx%2 == 0) mx--;
        mx = (mx+1)/2;
        sum += mx*mx*p[i];
        ans += mx;
    }
    rep(i, 0, n){
        if((ok+1)%p[i] != 0) continue;
        if((ok+1)/p[i]%2 == 0) continue;
        if(sum+ok+1 <= m){
            sum += ok+1;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}