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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, k; cin >> n >> k;
    long double p = 0.0;
    long double ldn = n, ldk = k;
    p += 1.0/(ldn*ldn*ldn);
    p += 3.0*(ldn-1.0)/(ldn*ldn*ldn);
    p += 6.0*(ldk-1.0)*(ldn-ldk)/(ldn*ldn*ldn);
    cout << setprecision(20) << p << endl;
    return 0;
}