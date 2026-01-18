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
    int n, m; cin >> n >> m;
    vector<pair<ll, ll>> pl(n);
    rep(i, 0, n){
        cin >> pl[i].first >> pl[i].second;
    }

    sort(pl.rbegin(), pl.rend());
    ll sum = 0;
    rep(i, 0, m) sum += pl[i].first;

    ll ans = 0;
    rep(i, 0, m) chmax(ans, sum*pl[i].second);
    rep(i, m, n) chmax(ans, (sum-pl[m-1].first+pl[i].first)*pl[i].second);

    cout << ans << endl;

    return 0;
}