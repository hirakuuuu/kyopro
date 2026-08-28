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

ll power(ll a, ll b, ll m){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    int k, m; cin >> k >> m;
    vector<ll> c(k), l(k);
    rep(i, 0, k){
        cin >> c[i] >> l[i];
    }

    ll r = 0;
    m *= 10007;
    {
        vector<ll> ten(31);
        ten[0] = 10%m;
        rep(i, 1, 31) ten[i] = (ten[i-1]*ten[i-1])%m;
        vector<ll> v(31);
        v[0] = 1%m;
        rep(i, 1, 31){
            v[i] = (v[i-1]*ten[i-1]+v[i-1])%m;
            // cout << ten[i] << ' ' << v[i] << endl;
        }

        ll acc = 0;
        ll ans = 0;
        rrep(i, k-1, 0){
            ll tmp = 0;
            rep(j, 0, 31){
                if(l[i]>>j&1){
                    tmp *= ten[j];
                    tmp += v[j];
                    tmp %= m;
                }
            }
            tmp = (tmp*power(10, acc, m))%m;
            ans += tmp*c[i];
            ans %= m;
            acc += l[i];
        }
        r = ans;
    }

    // cout << r2 << ' ' << r1 << endl;
    m /= 10007;
    cout << r/m << endl;
    return 0;
}