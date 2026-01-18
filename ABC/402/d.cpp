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
    ll n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    vector<ll> ab(n);
    rep(i, 0, m){
        cin >> a[i] >> b[i]; a[i]--, b[i]--;
        ab[(a[i]+b[i])%n]++;
    }

    ll ans = m*(m-1)/2;
    rep(i, 0, n){
        ans -= ab[i]*(ab[i]-1)/2;
    }
    cout << ans << endl;
    
    return 0;
}