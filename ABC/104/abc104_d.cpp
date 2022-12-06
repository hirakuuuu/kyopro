#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc104/tasks/abc104_d

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<ll> cnt_q(n+1);
    rep(i, 0, n){
        if(s[i] == '?') cnt_q[i+1] = cnt_q[i]+1;
        else cnt_q[i+1] = cnt_q[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(3));
    rep(i, 0, n){
        if(s[i] == 'A'){
            dp[i+1][0] = dp[i][0]+power(3, cnt_q[i]);
            dp[i+1][1] = dp[i][1];
            dp[i+1][2] = dp[i][2];
        }else if(s[i] == 'B'){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1]+dp[i][0];
            dp[i+1][2] = dp[i][2];
        }else if(s[i] == 'C'){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1];
            dp[i+1][2] = dp[i][2]+dp[i][1];     
        }else{
            dp[i+1][0] = dp[i][0]*3+power(3, cnt_q[i]);
            dp[i+1][1] = dp[i][1]*3+dp[i][0];
            dp[i+1][2] = dp[i][2]*3+dp[i][1];
        }
        rep(j, 0, 3) dp[i+1][j] %= MOD;
    }

    cout << dp[n][2] << endl;
    
    return 0;
}