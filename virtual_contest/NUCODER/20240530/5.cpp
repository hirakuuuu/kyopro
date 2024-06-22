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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    string s; cin >> s;

    vector<vector<vector<mint>>> dp(n+1, vector<vector<mint>>(1<<10, vector<mint>(10)));
    rep(i, 0, n){
        int tmp = s[i]-'A';
        dp[i+1] = dp[i];
        dp[i+1][(1<<tmp)][tmp] += 1;
        rep(j, 1, 1<<10){
            if((j>>tmp)&1){
                dp[i+1][j][tmp] += dp[i][j][tmp];
            }else{
                rep(k, 0, 10){
                    dp[i+1][j+(1<<tmp)][tmp] += dp[i][j][k];
                }
            }
        }
    }
    mint ans = 0;
    rep(i, 1, 1<<10){
        rep(j, 0, 10){
            ans += dp[n][i][j];
        }
    }
    cout << ans.val() << endl;

    
    return 0;
}