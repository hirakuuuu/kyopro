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
    string s; cin >> s;
    vector<vector<mint>> dp(s.size()+1, vector<mint>(s.size()+1));
    dp[0][0] = 1;
    rep(i, 0, s.size()){
        if(s[i] != ')'){
            rep(j, 0, s.size()-1){
                dp[i+1][j+1] += dp[i][j];
            }
        }
        if(s[i] != '('){
            rep(j, 1, s.size()){
                dp[i+1][j-1] += dp[i][j];
            }
        }
    }
    cout << dp[s.size()][0].val() << endl;
    return 0;
}