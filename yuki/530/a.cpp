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
    int a, b, c, d; cin >> a >> b >> c >> d;
    int p, q, r, s; cin >> p >> q >> r >> s;
    int time = a*p+b*q+c*r+d*s;
    int t; cin >> t;
    if(time <= t){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}