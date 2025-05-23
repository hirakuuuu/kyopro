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
    vector<vector<ll>> x(n, vector<ll>(3));
    rep(i, 0, n){
        rep(j, 0, 3){
            cin >> x[i][j];
        }
    }

    ll ans = -INF;
    rep(i, 0, 8){
        vector<ll> c(n);
        rep(j, 0, n){
            rep(k, 0, 3){
                if((i>>k)&1) c[j] += x[j][k];
                else c[j] -= x[j][k];
            }
        }
        sort(c.rbegin(), c.rend());
        ll tmp = 0;
        rep(j, 0, m) tmp += c[j];
        chmax(ans, tmp);
    }
    cout << ans << endl;
    
    return 0;
}