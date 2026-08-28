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
    string s; cin >> s;
    int n = (int)s.size();
    vector<mint> dp(3);
    rep(i, 0, n){
        vector<mint> ndp = dp;
        rep(k, 0, 3){
            if(s[i]-'a' == k){
                ndp[k] += 1;
                ndp[k] += dp[(k+1)%3];
                ndp[k] += dp[(k+2)%3];
            }
        }
        swap(dp, ndp);
    }
    mint ans = 0;
    rep(i, 0, 3) ans += dp[i];
    cout << ans.val() << endl;
    return 0;
}