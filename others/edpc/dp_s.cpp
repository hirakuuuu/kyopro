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
// https://atcoder.jp/contests/dp/tasks/dp_s

int main(){
    string k; cin >> k;
    ll d; cin >> d;

    vector<vector<vector<ll>>> dp(10005, vector<vector<ll>>(d, vector<ll>(2)));
    rep(i, 0, k[0]-'0') dp[0][i%d][0]++;
    dp[0][(k[0]-'0')%d][1]++;

    rep(i, 1, k.size()){
        rep(j, 0, 10){
            rep(l, 0, d){
                dp[i][(l+j)%d][0] += dp[i-1][l][0];
                dp[i][(l+j)%d][0] %= MOD;
            }
        }
        rep(j, 0, k[i]-'0'+1){
            if(j == k[i]-'0'){
                rep(l, 0, d){
                    dp[i][(l+j)%d][1] += dp[i-1][l][1];
                    dp[i][(l+j)%d][1] %= MOD;
                }
            }else{
                rep(l, 0, d){
                    dp[i][(l+j)%d][0] += dp[i-1][l][1];
                    dp[i][(l+j)%d][0] %= MOD;
                }
            }
        }
    }
    ll ans = (dp[k.size()-1][0][0]+dp[k.size()-1][0][1])%MOD;
    cout << (ans+MOD-1)%MOD << endl;

    
    return 0;
}