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
    int h, w; cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> a[i][j];
        }
    }
    vector<ll> p(h+w-1);
    rep(i, 0, h+w-1) cin >> p[i];

    ll ok = INF, ng = max(-1LL, p[0]-a[0][0]-1);
    while(ok-ng > 1){
        ll mid = (ok+ng)/2;
        vector<vector<ll>> dp(h, vector<ll>(w, -INF));
        dp[0][0] = mid+a[0][0]-p[0];
        rep(i, 0, h) rep(j, 0, w){
            if(i > 0){
                if(dp[i-1][j]+a[i][j] >= p[i+j]){
                    chmax(dp[i][j], dp[i-1][j]+a[i][j]-p[i+j]);
                }
            }
            if(j > 0){
                if(dp[i][j-1]+a[i][j] >= p[i+j]){
                    chmax(dp[i][j], dp[i][j-1]+a[i][j]-p[i+j]);
                }
            }
        }
        if(dp[h-1][w-1] >= 0) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;


    return 0;
}