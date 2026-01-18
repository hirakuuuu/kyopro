#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
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
    rep(i, 0, h){
        cin >> s[i];
    }

    vector<vector<mint>> dp(h, vector<mint>(w));
    vector<vector<mint>> pc(h, vector<mint>(w));
    vector<vector<mint>> yc(h, vector<mint>(w));
    pc[0][0] = 1;
    rep(i, 0, h){
        rep(j, 0, w){
            if(i > 0){
                if(s[i-1][j] == 'Y' && s[i][j] == 'Y'){
                    dp[i][j] += dp[i-1][j]+pc[i-1][j]+yc[i-1][j]*2;
                    yc[i][j] += pc[i-1][j]+yc[i-1][j];
                }else{
                    dp[i][j] += dp[i-1][j];
                    yc[i][j] += yc[i-1][j];
                }
                pc[i][j] += pc[i-1][j];
            }
            if(j > 0){
                if(s[i][j-1] == 'Y' && s[i][j] == 'Y'){
                    dp[i][j] += dp[i][j-1]+pc[i][j-1]+yc[i][j-1]*2;
                    yc[i][j] += pc[i][j-1]+yc[i][j-1];
                }else{
                    dp[i][j] += dp[i][j-1];
                    yc[i][j] += yc[i][j-1];
                }
                pc[i][j] += pc[i][j-1];
            }
        }
    }
    cout << dp[h-1][w-1].val() << endl;

    
    return 0;
}