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
    int n, m; cin >> n >> m;
    vector<int> x(m), y(m);
    rep(i, 0, m){
        cin >> x[i] >> y[i];
    }
    map<int, bool> dp;
    map<int, vector<int>> porn;
    rep(i, 0, m){
        porn[x[i]].push_back(y[i]);
    }
    dp[n] = true;
    for(auto [_, vec]: porn){
        map<int, bool> dp_;
        for(auto xx: vec){
            if(0 < xx) dp_[xx] |= dp[xx-1];
            if(xx < 2*n) dp_[xx] |= dp[xx+1];
        }
        for(auto xx: vec){
            dp[xx] = dp_[xx];
        }
    }
    int ans = 0;
    for(auto [key, val]: dp){
        if(val) ans++;
    }
    cout << ans << endl;

    return 0;
}