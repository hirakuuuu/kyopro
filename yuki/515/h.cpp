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
    int n; cin >> n;
    string s; cin >> s;
    vector<mint> dp(3);
    dp[2] = 1;
    rep(i, 0, n){
        vector<mint> dp_(3);
        if(s[i] == 'L'){
            dp_[0] = dp[0]+dp[2];
        }else if(s[i] == 'R'){
            dp_[1] = dp[0]+dp[1]+dp[2];
        }else if(s[i] == 'U'){
            dp_[2] = dp[0]+dp[1]+dp[2];
        }else{
            dp_[0] = dp[0]+dp[2];
            dp_[1] = dp[0]+dp[1]+dp[2];
            dp_[2] = dp[0]+dp[1]+dp[2];
        }
        swap(dp, dp_);
    }
    cout << (dp[0]+dp[1]+dp[2]).val() << endl;
    
    return 0;
}