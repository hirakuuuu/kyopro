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
// div3_496

int main(){
    string s; cin >> s;
    int n = (int)s.size();
    vector<vector<int>> dp(n+1, vector<int>(3, -1));
    dp[0][0] = 0;
    int ans = 0;
    rep(i, 0, n){
        if(s[i] == '0'){
            ans++;
        }else{
            vector<int> dp(3, -1);
            dp[0] = 0;
            while(i < n && s[i] != '0'){
                vector<int> dp_ = dp;
                rep(j, 0, 3){
                    if(dp_[j] < 0) continue;
                    if((10*j+(s[i]-'0'))%3 == 0) chmax(dp[(10*j+(s[i]-'0'))%3], dp_[j]+1);
                    else chmax(dp[(10*j+(s[i]-'0'))%3], dp_[j]);
                    if((s[i]-'0')%3 == 0) chmax(dp[(s[i]-'0')%3], dp_[j]+1);
                    else chmax(dp[(s[i]-'0')%3], dp_[j]);
                }
                i++;
            }
            ans += dp[0];
            if(i < n) i--;
        }
    }
    cout << ans << endl;

    
    return 0;
}