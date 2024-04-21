#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

map<ll, long double> memo;
ll x, y;
long double a, dx, dy;
long double f(ll x){
    if(memo.find(x) != memo.end()) return memo[x];
    if(x == 0) return memo[x] = 0.0;
    long double sum = 0.0;
    rep(i, 2, 7) sum += f(x/i);
    return memo[x] = min(dx+f(x/a), (dy+sum/6.0)*6.0/5.0);
}

int main(){
    ll n; cin >> n >> a >> x >> y;
    dx = x, dy = y;
    cout << setprecision(20) << f(n) << endl;

    
    return 0;
}