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
    int n, l, r; cin >> n >> l >> r;

    vector<int> a(n), b(n);
    int sum_a = 0, sum_b = 0;
    rep(i, 0, n){
        cin >> a[i];
        sum_a += a[i];
    }
    rep(i, 0, n){
        cin >> b[i];
        sum_b += b[i];
    }

    vector<vector<int>> tot(n+1, vector<int>(n+1));
    rep(i, 0, n+1){
        rep(j, 0, n+1){
            if(i == 0 && j == 0){
                tot[i][j] = 0;
            }else if(i == 0){
                tot[i][j] = tot[i][j-1]+b[j-1];
            }else if(j == 0){
                tot[i][j] = tot[i-1][j]-a[i-1];
            }else{
                tot[i][j] = tot[i-1][j-1]-a[i-1]+b[j-1];
            }
        }
    }


    auto solve = [&](int m) -> mint {
        int thle = (sum_b-sum_a)-m;
        vector<vector<mint>> dp(n+1, vector<mint>(n+1));
        dp[0][0] = 1;
        rep(i, 0, 2*n){
            rep(j, 0, n+1){
                int k = i-j;
                if(!inr(0, k, n+1)) continue;
                if(j < k) continue;
                if(j < n && tot[j][k]-a[j] >= thle) dp[j+1][k] += dp[j][k];
                if(k < n && tot[j][k]+b[k] >= thle) dp[j][k+1] += dp[j][k];
            }
        }
        return dp[n][n];
    };

    cout << (solve(r)-solve(l-1)).val() << endl;
    
    return 0;
}