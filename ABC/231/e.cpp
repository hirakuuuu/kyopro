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
    int n;
    ll x; cin >> n >> x;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    map<pair<ll, int>, ll> memo;
    auto f = [&](auto self, ll tmp, int p) -> ll {
        if(memo.find({tmp, p}) != memo.end()) return memo[{tmp, p}];
        if(p == n-1) return memo[{tmp, p}] = tmp/a[p];
        ll cnt = (tmp%a[p+1])/a[p];
        return memo[{tmp, p}] = min(cnt+self(self, tmp-tmp%a[p+1], p+1), a[p+1]/a[p]-cnt+self(self, tmp-tmp%a[p+1]+a[p+1], p+1));
    };
    cout << f(f, x, 0) << endl;
    
    return 0;
}