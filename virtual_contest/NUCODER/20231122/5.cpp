#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

int main(){
    ll r, c, k; cin >> r >> c >> k;
    vector<vector<ll>> v(r, vector<ll>(c));
    rep(i, 0, k){
        ll rr, cc, vv; cin >> rr >> cc >> vv;
        rr--, cc--;
        v[rr][cc] = vv;
    }

    vector<vector<vector<ll>>> dp(r, vector<vector<ll>>(c, vector<ll>(4)));
    dp[0][0][1] = v[0][0];
    rep(i, 0, r){
        rep(j, 0, c){
            rep(l, 0, 4){
                if(i+1 < r){
                    chmax(dp[i+1][j][0], dp[i][j][l]); 
                    if(v[i+1][j] > 0) chmax(dp[i+1][j][1], dp[i][j][l]+v[i+1][j]); 
                }
                if(j+1 < c){
                    chmax(dp[i][j+1][l], dp[i][j][l]);
                    if(l < 3 && v[i][j+1] > 0) chmax(dp[i][j+1][l+1], dp[i][j][l]+v[i][j+1]);
                }
            }
        }
    }

    ll ans = 0;
    rep(i, 0, 4) chmax(ans, dp[r-1][c-1][i]);
    cout << ans << endl;



    
    return 0;
}