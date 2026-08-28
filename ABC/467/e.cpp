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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(n-1);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n-1) cin >> b[i];

    vector<ll> c(n);
    vector<ll> odd, even;
    ll sum_odd= 0, sum_even = 0;
    even.push_back(0LL);
    rep(i, 1, n){
        c[i] = (b[i-1]-(c[i-1]+a[i-1]+a[i])%m+m)%m;
        if(i%2 == 1) odd.push_back(c[i]), sum_odd += c[i];
        else even.push_back(c[i]), sum_even += c[i];
    }
    // rep(i, 0, n){
    //     cout << c[i] << ' ';
    // }
    // cout << endl;
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    ll ans = 0;
    rep(i, 0, n) ans += c[i];

    vector<ll> d(n);
    rep(i, 0, n){
        if(i%2 == 0) d[i] = (m-c[i])%m;
        else d[i] = c[i];
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());

    for(auto dd: d){
        ll tmp = sum_odd+sum_even;
        // cout << dd << endl;
        // cout << tmp << endl;
        ll cnt_even = lower_bound(even.begin(), even.end(), m-dd)-even.begin();
        tmp += (even.size())*dd;
        tmp -= (even.size()-cnt_even)*m;
        // cout << tmp << endl;
        ll cnt_odd = lower_bound(odd.begin(), odd.end(), m-(m-dd)%m)-odd.begin();
        tmp += (odd.size())*((m-dd)%m);
        tmp -= (odd.size()-cnt_odd)*m;

        // cout << tmp << endl;
        chmin(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}