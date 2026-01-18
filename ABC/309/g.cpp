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
    int n, x; cin >> n >> x;
    vector<vector<mint>> dp(n+1, vector<mint>(1<<(2*x+1)));
    dp[0][0] = 1;
    rep(i, 1, n+1){
        rep(j, 0, 1<<(2*x+1)){
            int k = ((j<<1)&((1<<(2*x+1))-1));
            rep(l, 0, 2*x+1){
                if(!inr(1, i+(x-l), n+1)) continue;
                if(!((k>>l)&1)){
                    dp[i][k+(1<<l)] += dp[i-1][k];
                }
            }
        }
        rep(j, 0, 1<<(2*x+1)){
            cout << i << ' ' << j << ' ' << dp[i][j].val() << endl;
        }
    }

    mint ans = 0;
    rep(i, 0, 1<<(2*x+1)) ans += dp[n][i];
    cout << ans.val() << endl;


    
    return 0;
}