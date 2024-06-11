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
    ll n; cin >> n;
    vector<mint> a(61), t(61);
    a[0] = n;
    t[0] = 1;
    ll m = n;
    while(m){
        t[0] *= 10;
        m /= 10;
    }

    rep(i, 1, 61){
        a[i] = a[i-1]*t[i-1]+a[i-1];
        t[i] = t[i-1]*t[i-1];
        // cout << i << ' ' << a[i].val() << ' ' << t[i].val() << endl;
    }
    mint ans = 0;
    rep(i, 0, 61){
        if((n>>i)&1){
            ans = ans*t[i]+a[i];
        }
    }
    cout << ans.val() << endl;

    
    return 0;
}