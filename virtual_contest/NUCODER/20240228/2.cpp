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
    vector<int> t(n);
    rep(i, 0, n) cin >> t[i];
    vector<bool> dp(100005);
    dp[0] = true;
    int total = 0;
    rep(i, 0, n){
        vector<bool> dp_(100005);
        rep(j, 0, 100005){
            if(dp[j] || (j-t[i] >= 0 && dp[j-t[i]])) dp_[j] = true;
        }
        swap(dp, dp_);
        total += t[i];
    }
    int ans = IINF;
    rep(i, 0, 100005){
        if(dp[i]) chmin(ans, max(i, total-i));
    }
    cout << ans << endl;

    
    return 0;
}