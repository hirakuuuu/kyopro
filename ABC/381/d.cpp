#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}



int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i], a[i]--;

    vector<int> dp(n);
    int ans = 0;
    vector<vector<int>> r(n, vector<int>(2, -1));
    r[a[0]][0] = 0;
    rep(i, 1, n){
        if(a[i] != a[i-1]) continue;
        dp[i] = dp[i-2]+2;
        if(inr(i-dp[i]+1, r[a[i]][i%2], i)){
            dp[i] = i-r[a[i]][i%2];
        }
        r[a[i]][i%2] = i;
        chmax(ans, dp[i]);
    }
    cout << ans << endl;
    
    return 0;
}