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

int popcount(int x){
    int res = 0;
    while(x){
        res += x&1;
        x >>= 1;
    }
    return res;
}

int main(){
    int n; cin >> n;
    ll ans = 0;
    ll mod = 998244353;
    rep(i, 0, n+1){
        rep(j, i, n+1){
            if(popcount(i) == popcount(j)) ans += (i&j), ans %= mod;
        }
    }
    cout << ans << endl;
    
    return 0;
}