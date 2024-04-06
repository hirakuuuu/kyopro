#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll dp[5][5][2505][2505];

int main(){
    int h, w; cin >> h >> w;
    vector<ll> r(h), c(w);
    rep(i, 0, h) cin >> r[i];
    rep(i, 0, w) cin >> c[i];
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, 0, h){
        string s; cin >> s;
        rep(j, 0, w){
            a[i][j] = s[j]-'0';
        }
    }
    ll ans = INF;

    rep(_, 0, 2){
        rep(i, 0, 2) rep(j, 0, 2) rep(k, 0, h) rep(l, 0, w) dp[i][j][k][l] = INF;
        if(a[0][0] == 0){
            dp[0][0][0][0] = 0;
            dp[1][1][0][0] = r[0]+c[0];
        }else{
            dp[1][0][0][0] = r[0];
            dp[0][1][0][0] = c[0];
        }
        rep(i, 0, h) rep(j, 0, w){
            if(i < h-1){
                rep(k, 0, 2){
                    if(!(a[i+1][j]^k)){
                        rep(l, 0, 2) chmin(dp[0][k][i+1][j], dp[l][k][i][j]);
                    }else{
                        rep(l, 0, 2) chmin(dp[1][k][i+1][j], dp[l][k][i][j]+r[i+1]);
                        // rep(l, 0, 2) chmin(dp[0][1][i+1][j], dp[l][0][i][j]+c[j]);
                    }
                }
            }
            if(j < w-1){
                rep(k, 0, 2){
                    if(!(a[i][j+1]^k)){
                        rep(l, 0, 2) chmin(dp[k][0][i][j+1], dp[k][l][i][j]);
                    }else{
                        rep(l, 0, 2) chmin(dp[k][1][i][j+1], dp[k][l][i][j]+c[j+1]);
                        // rep(l, 0, 2) chmin(dp[1][0][i][j+1], dp[0][l][i][j]+r[i]);
                    }
                }
            }
        }

        rep(i, 0, 2) rep(j, 0, 2) chmin(ans, dp[i][j][h-1][w-1]);
        rep(i, 0, h){
            rep(j, 0, w){
                a[i][j] = 1-a[i][j];
            }
        }
    }
    cout << ans << endl;


    return 0;
}