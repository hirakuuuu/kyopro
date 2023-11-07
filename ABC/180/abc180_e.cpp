#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc180/tasks/abc180_e

int main(){
    int n; cin >> n;
    vector<int> x(n), y(n), z(n);
    rep(i, 0, n){
        cin >> x[i] >> y[i] >> z[i];
    }
    vector<vector<int>> dist(n, vector<int>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            dist[i][j] = abs(x[j]-x[i])+abs(y[j]-y[i])+max(0, z[j]-z[i]);
        }
    }

    vector<vector<int>> dp(1<<n, vector<int>(n, IINF));
    dp[1][0] = 0;
    rep(i, 1, 1<<n){
        rep(j, 0, n){
            rep(k, 0, n){
                if(j == k) continue;
                if((i>>j)&1 && !((i>>k)&1)){
                    chmin(dp[i+(1<<k)][k], dp[i][j]+dist[j][k]);
                }
            }
        }
    }

    int ans = IINF;
    rep(i, 0, n){
        chmin(ans, dp[(1<<n)-1][i]+dist[i][0]);
    }
    cout << ans << endl;
    
    return 0;
}