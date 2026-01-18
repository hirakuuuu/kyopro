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
    auto f = [&](ll x) -> ll {
        string sx = to_string(x);
        reverse(sx.begin(), sx.end());
        ll res = 0;
        for(auto ss: sx){
            res *= 10;
            res += ss-'0';
        }
        return res;
    };

    ll x, y; cin >> x >> y;
    vector<ll> a(10);
    a[0] = x, a[1] = y;
    rep(i, 2, 10){
        a[i] = f(a[i-1]+a[i-2]);
    }
    cout << a[9] << endl;

    return 0;
}