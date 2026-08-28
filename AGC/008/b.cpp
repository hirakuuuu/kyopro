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
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    vector<ll> acc(n+1);
    rep(i, 0, n){
        acc[i+1] = acc[i]+a[i];
    }
    vector<ll> plus_l(n+1), plus_r(n+1);
    rep(i, 0, n){
        plus_l[i+1] = plus_l[i];
        if(a[i] > 0) plus_l[i+1] += a[i];
    }
    rrep(i, n-1, 0){
        plus_r[i] = plus_r[i+1];
        if(a[i] > 0) plus_r[i] += a[i];
    }

    ll ans = 0;
    rep(l, 0, n-k+1){
        int r = l+k;
        chmax(ans, plus_l[l]+max(0LL, acc[r]-acc[l])+plus_r[r]);
    }
    cout << ans << endl;
    return 0;
}