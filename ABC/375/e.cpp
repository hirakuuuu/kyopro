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
    vector<int> a(n), b(n);
    int sum_b = 0;
    rep(i, 0, n){
        cin >> a[i] >> b[i];
        a[i]--;
        sum_b += b[i];
    }
    if(sum_b%3 != 0){
        cout << -1 << endl;
        return 0;
    }

    int m = sum_b/3;
    vector<vector<int>> dp(m+1, vector<int>(m+1, IINF));
    dp[0][0] = 0;
    rep(i, 0, n){
        vector<vector<int>> dp_(m+1, vector<int>(m+1, IINF));
        rep(j, 0, m+1){
            rep(k, 0, m+1){
                if(j+b[i] <= m) chmin(dp_[j+b[i]][k], dp[j][k]+(a[i] != 0));
                if(k+b[i] <= m) chmin(dp_[j][k+b[i]], dp[j][k]+(a[i] != 1));
                chmin(dp_[j][k], dp[j][k]+(a[i] != 2));
            }
        }
        swap(dp, dp_);
    }
    if(dp[m][m] == IINF) cout << -1 << endl;
    else cout << dp[m][m] << endl;
    
    return 0;
}