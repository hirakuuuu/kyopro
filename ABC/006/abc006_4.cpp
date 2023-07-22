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
// https://atcoder.jp/contests/abc006/tasks/abc006_4


int main(){
    int n; cin >> n;
    vector<int> dp(n+1, 1001001001);
    dp[0] = 0;
    rep(i, 0, n){
        int c; cin >> c;
        int pos = lower_bound(dp.begin(), dp.end(), c)-dp.begin();
        dp[pos] = c;
    }
    int ans = 0;
    rep(i, 0, n+1){
        if(dp[i] == 1001001001) break;
        ans++;
    }

    cout << n+1-ans << endl;

    return 0;
}