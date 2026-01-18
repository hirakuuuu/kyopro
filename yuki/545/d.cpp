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

ll gcd(ll a, ll b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

int main(){
    ll n; cin >> n;
    ll a, b; cin >> a >> b;

    ll cnt_a = n/a;
    ll cnt_b = n/b;
    ll cnt_ab = n/lcm(a, b);
    cout << n-(cnt_a+cnt_b)+cnt_ab << endl;
    return 0;
}