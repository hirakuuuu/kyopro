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
    int n, m; cin >> n >> m;
    
    vector<ll> a(2*n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) a[i+n] = a[i];

    vector<ll> acc(2*n+1);
    rep(i, 0, 2*n) acc[i+1] = acc[i]+a[i];

    // s → t の距離
    vector<int> cnt(m);
    ll ans = 0;
    rep(s, 0, 2*n){
        if(s >= n) cnt[acc[s-n]%m]--;
        ans += (ll)cnt[acc[s]%m];
        if(s < n) cnt[acc[s]%m]++;
        // cout << s << ' ' << ans << endl;
    }
    cout << ans << endl;

    
    return 0;
}