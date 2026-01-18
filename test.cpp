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
    auto f = [&](double x) -> double {
      return x/log2(x);
    };
    double ok = 1e18, ng = 0.0;
    while((ok-ng) > 1e-9){
        double mid = (ok+ng)/2;
        if(f(mid) > 8000) ok = mid;
        else ng = mid;
    }
    cout << setprecision(10) << ok << endl;
    cout << setprecision(10) << f(ok-1) << endl;
    cout << setprecision(10) << f(ok) << endl;



    
    return 0;
}