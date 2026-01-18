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

    auto calc = [&](ll x, ll y) -> ll {
        // -4 -> -3, -2 -> -2, -1 -> -1, 1 -> 0, 2 -> 1, 4 -> 2 ...
        if(x > 0) x = (x-x/3)-1;
        else x = x+(2-x)/3-1;

        if(y > 0) y = (y-y/3)-1;
        else y = y+(2-y)/3-1;

        if(x == 0 && y == 0) return 0;
        if(x == 1 && y == 1) return 1;
        return max(abs(x), abs(y))+(x==y);
    };

    int t; cin >> t;
    while(t--){

        ll x = 0, y = 0;
        rep(i, 0, 3){
            ll ax, ay; cin >> ax >> ay; 
            x += ax, y += ay;
        }
        cout << calc(x, y) << endl;
    }
    return 0;
}