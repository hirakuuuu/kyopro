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
    ll s; cin >> s;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    if(n <= 20){
        ll ans = 0;
        rep(i, 0, 1<<n){
            ll tmp = 0;
            rep(j, 0, n){
                if((i>>j)&1) tmp += a[j];
            }
            if(tmp == s) ans++;
        }
        cout << ans << endl;
        return 0;
    }
    vector<ll> l(1<<20);
    rep(i, 0, 1<<20){
        rep(j, 0, 20){
            if((i>>j)&1) l[i] += a[j];
        }
    }
    vector<ll> r(1<<(n-20));
    rep(i, 0, 1<<(n-20)){
        rep(j, 0, n-20){
            if((i>>j)&1) r[i] += a[j+20];
        }
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    ll ans = 0;
    rep(i, 0, 1<<20){
        if(s-l[i] < 0) continue;
        ans += upper_bound(r.begin(), r.end(), s-l[i])-lower_bound(r.begin(), r.end(), s-l[i]);
    }
    cout << ans << endl;
    return 0;
}