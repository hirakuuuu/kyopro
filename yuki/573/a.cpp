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
    ll n, a, b; cin >> n >> a >> b;
    __int128_t f = 1;
    rep(i, 2, n+2) f *= i; 
    __int128_t I = 0;
    __int128_t A = 1, B = 1;
    rep(i, 0, n+1){
        int12 k; cin >> k;
        A *= a;
        B *= b;
        I += (f/(i+1))*k*(B-A);
    }
    cout << I/f << endl;
    
    return 0;
}