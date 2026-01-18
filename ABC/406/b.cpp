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
    ll n, k; cin >> n >> k;
    ll num = 1;
    ll mx = 1;
    rep(i, 0, k) mx *= 10;
    rep(i, 0, n){
        ll a; cin >> a;
        if((mx%a == 0 && num >= mx/a) || num > mx/a){
            num = 1;
        }else{
            num *= a;
        }
    }
    cout << num << endl;
    return 0;
}