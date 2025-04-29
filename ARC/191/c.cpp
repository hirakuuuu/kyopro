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

constexpr ll MOD = 256;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
- A と M は互いに素
- 
*/

int main(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        if(n == 1){
            cout << 1 << ' ' << 1 << endl;
            continue;
        }
        cout << n+1 << ' ' << n*n << endl;
    }


    // cout << "m: " << MOD << endl;
    // rep(i, 2, MOD){
    //     ll a = i%MOD, n = 1, tmp = a;
    //     if(gcd(a, MOD) != 1) continue;
    //     while(tmp != 1){
    //         n++;
    //         tmp *= a;
    //         tmp %= MOD;
    //     }
    //     cout << a << ": " << n << endl;
    // }

    return 0;
}