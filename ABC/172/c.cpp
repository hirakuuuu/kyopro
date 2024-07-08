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
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    vector<ll> acc_a(n+1), acc_b(m+1);
    rep(i, 0, n) acc_a[i+1] = acc_a[i]+a[i];
    rep(i, 0, m) acc_b[i+1] = acc_b[i]+b[i];
    

    ll ans = 0;
    rep(i, 0, n+1){
        if(k-acc_a[i] < 0) break;
        int pos = upper_bound(acc_b.begin(), acc_b.end(), k-acc_a[i])-acc_b.begin();
        chmax(ans, i+pos-1);
    }
    cout << ans << endl;

    
    return 0;
}