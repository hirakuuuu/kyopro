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
    int m, n; cin >> m >> n;
    vector<int> x(m);
    vector<int> rev(m);
    rep(i, 0, m){
        cin >> x[i];
        x[i]--;
        rev[x[i]] += 1<<i;
    }
    vector<vector<mint>> dp(n, vector<mint>(1<<m));
    rep(i, 0, m){
        if(x[i] == i) dp[0][(1<<m)-1] += 1;
        else dp[0][((1<<m)-1)-(1<<i)] += 1;
    }
    rep(i, 1, n){
        rep(j, 0, 1<<m){
            rep(k, 0, m){
                if((j>>k)&1){
                    dp[i][((j-(1<<k))|rev[k])] += dp[i-1][j];
                }
            }
        }
    }
    mint ans = 0;
    rep(i, 0, 1<<m){
        ans += dp[n-1][i];
    }
    cout << ans.val() << endl;

    
    return 0;
}