#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> p(n);
    rep(i, 0, n){
        cin >> p[i]; p[i]--;
    }

    vector<int> c(n);
    vector<vector<int>> g(n);
    rep(i, 0, n){
        cin >> c[i]; c[i]--;
        g[c[i]].push_back(p[i]);
    }

    ll ans = 0;
    rep(i, 0, n){
        int m = g[i].size();
        vector<int> dp(m, IINF);
        for(auto ng: g[i]){
            int pos = lower_bound(dp.begin(), dp.end(), ng)-dp.begin();
            dp[pos] = ng;
        }
        ll len = 0;
        rep(j, 0, m){
            if(dp[j] == IINF) break;
            len++;
        }
        ans += (ll)(i+1)*(m-len);
    }
    cout << ans << endl;
    return 0;
}