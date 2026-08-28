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
    vector<vector<ll>> a(m, vector<ll>(n));
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> a[j][i];
        }
    }
    ll ans = 0;
    rep(i, 0, m){
        sort(a[i].begin(), a[i].end());

        ll acc = a[i][0];
        rep(j, 1, n){
            ans += a[i][j]*j-acc;
            acc += a[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}