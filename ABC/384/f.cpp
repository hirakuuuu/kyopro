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
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    const int K = 25;
    vector<ll> d(K+1);
    rep(i, 0, K+1){
        map<ll, pair<ll, ll>> memo;
        ll two = (1<<i);
        rep(j, 0, n){
            ll r = a[j]&(two-1);
            ll q = (two-r)&(two-1);
            memo[r].first++;
            memo[r].second += a[j];
            d[i] += a[j]*memo[q].first+memo[q].second;
        }
    }
    ll ans = 0;
    rep(i, 0, K){
        ans += (d[i]-d[i+1])>>i;
    }
    cout << ans << endl;
    return 0;
}