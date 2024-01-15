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
// 

int main(){
    int n; cin >> n;
    vector<double> dp(n+1);
    dp[1] = 3.5;
    rep(i, 2, n+1){
        if(dp[i-1] < 4){
            dp[i] = 2.5+dp[i-1]/2;
        }else if(dp[i-1] < 5){
            dp[i] = 11.0/6.0+2.0*dp[i-1]/3.0;
        }else{
            dp[i] = 1.0+5.0*dp[i-1]/6.0;
        }
    }
    printf("%.20f\n", dp[n]);

    
    return 0;
}