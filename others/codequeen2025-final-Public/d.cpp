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
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<pair<ll, int>> acc(n+1);
    rep(i, 0, n){
        cin >> a[i];
        b[i] = a[i]-k;
        acc[i+1] = {acc[i].first+b[i], -(i+1)};
    }
    sort(acc.rbegin(), acc.rend());
    int ans = -1, mi = IINF;
    rep(i, 0, n+1){
        auto [val, r] = acc[i];
        r = -r;
        // cout << val << ' ' << r << endl;
        if(mi < r) chmax(ans, r-mi);
        // cout << r << ' ' << mi << endl;
        chmin(mi, r);
    }
    cout << ans << endl;

    return 0;
}