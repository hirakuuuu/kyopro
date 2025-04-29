#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];
    vector<vector<mint>> dp(h+1, vector<mint>(h+1));
    dp[2][1] = 1;
    rep(i, 3, h+w){
        vector<vector<mint>> ndp(h+1, vector<mint>(h+1));
        rep(j, 1, i){
            if(!inr(1, j, h+1) || !inr(1, i-j, w+1)) continue;
            rep(k, 1, i){
                if(!inr(1, k, h+1) || !inr(1, i-k, w+1)) continue;
                if(j == k) continue;

                // if(s[k-1][i-k-1] == '#') continue;
                
                if(i-j < w && s[j-1][i-j] != '#' && i-k < w && s[k-1][i-k] != '#') ndp[j][k] += dp[j][k];
                if(i-j < w && s[j-1][i-j] != '#' && k < h && s[k][i-k-1] != '#') ndp[j][k+1] += dp[j][k];
                if(j < h && s[j][i-j-1] != '#' && i-k < w && s[k-1][i-k] != '#') ndp[j+1][k] += dp[j][k];
                if(j < h && s[j][i-j-1] != '#' && k < h && s[k][i-k-1] != '#') ndp[j+1][k+1] += dp[j][k];
            }
        }
        swap(ndp, dp);
    }
    cout << dp[h][h].val() << endl;
    return 0;
}