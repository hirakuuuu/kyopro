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
    ll n, k, c; cin >> n >> k >> c;
    string s; cin >> s;
    vector<ll> dp(n+1);
    rep(i, 1, n+1){
        dp[i] = dp[i-1];
        if(s[i-1] == 'o'){
            if(i <= c) chmax(dp[i], 1);
            else chmax(dp[i], dp[i-c-1]+1);
        }
    }
    vector<ll> dp_(n+1);
    rrep(i, n-1, 0){
        dp_[i] = dp_[i+1];
        if(s[i] == 'o'){
            if(i >= n-c) chmax(dp_[i], 1);
            else chmax(dp_[i], dp_[i+c+1]+1); 
        }
    }

    if(dp[n] == k){
        rep(i, 1, n+1){
            if(dp[i]-dp[i-1] > 0 && dp_[i-1]-dp_[i] > 0) cout << i << endl;
        }
    }

    

    return 0;
}