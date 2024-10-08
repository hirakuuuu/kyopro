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
    int n; cin >> n;
    vector<ll> k(n);
    rep(i, 0, n) cin >> k[i];

    ll ans = INF;
    rep(i, 0, 1<<n){
        ll a = 0, b = 0;
        rep(j, 0, n){
            if((i>>j)&1) a += k[j];
            else b += k[j]; 
        }
        chmin(ans, max(a, b));
    }
    cout << ans << endl;
    return 0;
}