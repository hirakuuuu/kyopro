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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*

*/

int main(){
    int n, s; cin >> n >> s;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];
    vector<vector<bool>> dp(n+1, vector<bool>(s+1));
    dp[0][0] = true;
    rep(i, 0, n){
        rep(j, 0, s+1){
            if(j+a[i] <= s && dp[i][j]) dp[i+1][j+a[i]] = true;
            if(j+b[i] <= s && dp[i][j]) dp[i+1][j+b[i]] = true;
        }
    }
    if(!dp[n][s]){
        cout << "Impossible" << endl;
        return 0;
    }

    string ans;
    int sum = s;
    rrep(i, n-1, 0){
        if(sum-a[i] >= 0 && dp[i][sum-a[i]]){
            sum -= a[i];
            ans += 'A';
        }else if(sum-b[i] >= 0 && dp[i][sum-b[i]]){
            sum -= b[i];
            ans += 'B';
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}