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
    int n; cin >> n;
    vector<int> a(n), w(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> w[i];

    ll ans = 0;
    vector<ll> sum(n), mx(n);
    rep(i, 0, n){
        a[i]--;
        sum[a[i]] += w[i];
        chmax(mx[a[i]], w[i]);
    }
    rep(i, 0, n){
        if(sum[i] == mx[i]) continue;
        ans += sum[i]-mx[i];
    }
    cout << ans << endl;
    
    return 0;
}