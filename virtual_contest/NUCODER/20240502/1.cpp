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
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> acc(n);
    rep(i, 1, n){
        if(i%2 == 0) acc[i] = acc[i-1]+(a[i]-a[i-1]);
        else acc[i] = acc[i-1];
    }
    int q; cin >> q;
    while(q--){
        ll l, r; cin >> l >> r;
        int pl = lower_bound(a.begin(), a.end(), l)-a.begin();
        int pr = lower_bound(a.begin(), a.end(), r)-a.begin();
        ll tmp = acc[pr]-acc[pl];
        if(pl%2 == 0) tmp += a[pl]-l;
        if(pr%2 == 0) tmp -= a[pr]-r;
        cout << tmp << endl;
    }
    
    return 0;
}