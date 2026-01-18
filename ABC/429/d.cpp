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
    ll n, m, c; cin >> n >> m >> c;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<ll> aa(2*n);
    rep(i, 0, n){
        aa[i] = a[i];
        aa[i+n] = aa[i]+m;
    }

    ll ans = 0;
    if(a[0] > 0){
        // 0 ~ a[0]-1 まで
        ll ng = 0, ok = m;
        while(ok-ng > 1){
            ll mid = (ok+ng)/2;
            ll cnt = upper_bound(aa.begin(), aa.end(), mid)-aa.begin();
            if(cnt >= c) ok = mid;
            else ng = mid;
        }
        ll cnt = upper_bound(aa.begin(), aa.end(), ok)-aa.begin();
        ans += cnt*a[0];
    }
    // cout << ans << endl;
    a.push_back(m);
    rep(i, 0, n){
        // a[i]~a[i]-1 まで
        ll ng = a[i], ok = a[i]+m;
        while(ok-ng > 1){
            ll mid = (ok+ng)/2;
            ll cnt = upper_bound(aa.begin(), aa.end(), mid)-(aa.begin()+i+1);
            // cout << cnt << ' ' << mid << endl;
            if(cnt >= c) ok = mid;
            else ng = mid;
        }
        ll cnt = upper_bound(aa.begin(), aa.end(), ok)-(aa.begin()+i+1);
        ans += cnt*(a[i+1]-a[i]);
        // cout << ok << ' ' <<cnt << ' ' << ans << endl;
    }
    cout << ans << endl;
    return 0;
}