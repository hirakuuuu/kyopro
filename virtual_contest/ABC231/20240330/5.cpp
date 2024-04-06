#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int n; cin >> n;
    ll x; cin >> x;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    map<pair<ll, int>, ll> memo;
    auto f = [&](auto self, ll tmp, int i) -> ll {
        if(memo.find({tmp, i}) != memo.end()) return memo[{tmp, i}];
        if(i == n-1) return memo[{tmp, i}] = tmp/a[i];
        ll res = INF;
        chmin(res, (tmp%a[i+1])/a[i]+self(self, tmp-tmp%a[i+1], i+1));
        chmin(res, (a[i+1]-tmp%a[i+1])/a[i]+self(self, tmp-tmp%a[i+1]+a[i+1], i+1));
        return memo[{tmp, i}] = res;
    };
    cout << f(f, x, 0) << endl;
    return 0;
}