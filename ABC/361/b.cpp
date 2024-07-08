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

/*
１次元の問題を解くと、共通部分の長さが正になるかどうかを考えればいい
これを３次元に応用すると、各次元の共通部分の長さが正になればよいということがわかる
*/

int main(){
    vector<ll> x(4);
    vector<ll> y(4);
    vector<ll> z(4);
    rep(i, 0, 4) cin >> x[i] >> y[i] >> z[i];

    ll dx = 0, dy = 0, dz = 0;
    if(x[1] <= x[2]) dx = 0;
    else if(x[3] <= x[0]) dx = 0;
    else if(x[2] < x[1]) dx = x[1]-x[2];
    else dx = x[3]-x[0]; 
    
    if(y[1] <= y[2]) dy = 0;
    else if(y[3] <= y[0]) dy = 0;
    else if(y[2] < y[1]) dy = y[1]-y[2];
    else dy = y[3]-y[0]; 

    if(z[1] <= z[2]) dz = 0;
    else if(z[3] <= z[0]) dz = 0;
    else if(z[2] < z[1]) dz = z[1]-z[2];
    else dz = z[3]-z[0]; 

    if(dx*dy*dz) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}