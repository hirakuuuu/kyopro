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
    auto f = [&](ll n) -> ll {
        ll res = 0;
        while(n){
            res += n%10;
            n /= 10;
        }
        return res;
    };

    ll n; cin >> n;
    vector<ll> a(n+1);
    a[0] = 1;
    ll tot = 0;
    rep(i, 1, n+1){
        a[i] = tot+f(a[i-1]);
        tot += f(a[i-1]);
    }
    cout << a[n] << endl;
    return 0;
}