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
// https://atcoder.jp/contests/arc160/tasks/arc160_c

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    rep(i, 1, n) a[i] -= a[0];
    a[0] = 0;
    vector<int> cnt(200005);
    rep(i, 0, n) cnt[a[i]]++;
    
    vector<ll> dp = {1};
    rep(i, 0, 200005){
        dp[dp.size()-1] %= MOD;
        rrep(j, dp.size()-1, 1){
            dp[j-1] += dp[j];
            dp[j-1] %= MOD;
        }

        vector<ll> dp_;
        rep(j, 0, (dp.size()-1+cnt[i])/2+1){
            dp_.push_back(dp[max(0, j*2-cnt[i])]);
        }

        dp = dp_;

    }


    cout << dp[0] << endl;
    return 0;
}