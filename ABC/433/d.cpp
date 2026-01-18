#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    vector<unordered_map<ll, ll>> cnt(11);
    vector<ll> ten(11);
    ten[0] = 1;
    rep(i, 1, 11) ten[i] = (ten[i-1]*10)%m;
    rep(i, 0, n){
        cin >> a[i];
        rep(j, 1, 11){
            ll tmp = (a[i]*ten[j])%m;
            cnt[j][tmp]++;
        }
    }

    ll ans = 0;
    rep(i, 0, n){
        int len = (int)to_string(a[i]).size();
        ll tmp = (m-a[i]%m)%m;
        ans += cnt[len][tmp];
    }
    cout << ans << endl;
    return 0;
}