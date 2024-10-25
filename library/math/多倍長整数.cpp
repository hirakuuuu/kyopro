#include <bits/stdc++.h>
// #include <atcoder/all>

// 多倍長整数
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

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

// verify: https://atcoder.jp/contests/abc180/tasks/abc180_d
int main(){
    cpp_int x, y, a, b; cin >> x >> y >> a >> b;
    cpp_int ans = 0;

    while(true){
        if(x*a > x+b || x*a >= y) break;
        x *= a;
        ans++;
    }
    ans += (y-1-x)/b;
    cout << ans << endl;
    
    return 0;
}