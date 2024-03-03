#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc343/tasks/abc343_g

int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    vector<vector<int>> d(n, vector<int>(n, -1));
    vector<vector<bool>> inc(n, vector<bool>(n));

    rep(i, 0, n){
        rep(j, 0, n){
            // 完全に含む場合
            ll sum_i = 0, sum_j = 0, o = 1, tmp = 0;
            if(s[i].size() >= s[j].size()){
                rep(k, 0, s[j].size()) sum_j = (sum_j*26+(s[j][k]-'a'))%MOD;
                rep(k, 0, s[j].size()) sum_i = (sum_i*26+(s[i][k]-'a'))%MOD;
                rep(k, 0, s[j].size()) o = (o*26)%MOD;
                rep(k, s[j].size(), s[i].size()){
                    if(sum_j == sum_i) inc[i][j] = true;
                    sum_i = (sum_i*26+(s[i][k]-'a'))%MOD;
                    sum_i = (sum_i-(s[i][k-s[j].size()]-'a')*o%MOD+MOD)%MOD;
                }
                if(sum_i == sum_j) inc[i][j] = true;
            }
            // 部分的に含む場合
            sum_i = 0, sum_j = 0, o = 1, tmp = 0;
            rep(k, 0, min(s[i].size(), s[j].size())){
                sum_j = (sum_j*26+(s[j][k]-'a'))%MOD;
                sum_i = (sum_i+(s[i][s[i].size()-k-1]-'a')*o)%MOD;
                o = (o*26)%MOD;
                if(sum_j == sum_i){
                    tmp = k+1;
                }
            }
            d[i][j] = s[j].size()-tmp;
        }
    }
    vector<vector<int>> dp(1<<n, vector<int>(n, IINF));
    rep(i, 0, n){
        dp[(1<<i)][i] = s[i].size();
    }
    rep(i, 1, 1<<n){
        rep(j, 0, n){
            if(!((i>>j)&1)){
                rep(k, 0, n){
                    if((i>>k)&1){
                        if(dp[i][k] == IINF) continue;
                        if(inc[k][j]) chmin(dp[i+(1<<j)][k], dp[i][k]);
                        chmin(dp[i+(1<<j)][j], dp[i][k]+d[k][j]);
                    }
                }
            }
        }
    }
    int ans = IINF;
    rep(i, 0, n) chmin(ans, dp[(1<<n)-1][i]);
    cout << ans << endl;
    
    return 0;
}