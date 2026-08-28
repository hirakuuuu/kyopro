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
    vector<string> s(n);
    vector<vector<int>> cnt_b(n, vector<int>(n+1));
    rep(i, 0, n){
        cin >> s[i];
        rep(j, 0, n){
            cnt_b[i][j+1] = cnt_b[i][j];
            if(s[i][j] == '#') cnt_b[i][j+1]++;
        }
    }

    vector<int> dp(n+1);
    rep(i, 0, n){
        vector<int> ndp(n+1, IINF);
        int mi = dp[n];
        rrep(j, n, 0){
            chmin(mi, dp[j]);
            int tmp = (cnt_b[i][j])+(n-j-(cnt_b[i][n]-cnt_b[i][j]));
            chmin(ndp[j], mi+tmp);
        }
        swap(dp, ndp);
        // rep(i, 0, n+1){
        //     cout << dp[i] << ' ';
        // }
        // cout << endl;
    }

    int ans = IINF;
    rep(i, 0, n+1) chmin(ans, dp[i]);
    cout << ans << endl;
    return 0;
}