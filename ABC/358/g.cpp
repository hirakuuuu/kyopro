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
    int h, w;
    ll k; cin >> h >> w >> k;
    int sx, sy; cin >> sx >> sy;
    sx--, sy--;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> dp(h, vector<ll>(w, -INF));
    ll ans = k*a[sx][sy];
    dp[sx][sy] = 0;
    rep(i, 1, min(k, 2500LL)+1){
        vector<vector<ll>> dp_ = dp;
        rep(x, 0, h){
            rep(y, 0, w){
                rep(l, 0, 4){
                    int nx = x+(l-1)%2, ny = y+(l-2)%2;
                    if(!inr(0, nx, h) || !inr(0, ny, w)) continue;
                    chmax(dp[x][y], dp_[nx][ny]);
                }
                dp[x][y] += a[x][y];
            }
        }
        rep(x, 0, h){
            rep(y, 0, w){
                chmax(ans, dp[x][y]+(k-i)*a[x][y]);
            }
        }
    }

    cout << ans << endl;

    
    return 0;
}