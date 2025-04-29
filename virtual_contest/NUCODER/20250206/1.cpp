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
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll acc = 0, sum = 0;
    rep(i, 0, m){
        acc += a[i];
        sum += a[i]*(i+1);
    }
    ll ans = sum;
    rep(i, m, n){
        sum -= acc;
        sum += m*a[i];
        acc -= a[i-m];
        acc += a[i];
        chmax(ans, sum);
    }
    cout << ans << endl;    
    return 0;
}