#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
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
    ll n, k; cin >> n >> k;
    if(k == 0){
        cout << n*n << endl;
        return 0;
    }
    ll ans = 0;
    // b > k
    rep(b, k+1, n+1){
        // a \ge k (mod b)
        ans += (n/b)*(b-k);
        ans += max(0LL, n%b-k+1);
        // cout << b << ' ' << ans << endl;
    }
    cout << ans << endl;
    return 0;
}