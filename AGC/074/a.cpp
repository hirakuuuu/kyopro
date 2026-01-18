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
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<int>> g(n);
        rep(i, 0, m){
            int x, y; cin >> x >> y; x--, y--;
            g[x].push_back(y);
        }
        vector<int> p(n);
        rep(i, 0, n){
            int x; cin >> x; x--;
            p[x] = i;
        }
        vector<int> dp(n, 1);
        rrep(i, n-1, 0){
            for(auto j: g[p[i]]){
                chmax(dp[p[i]], dp[j]+1);
            }
            if(i <= n-2){
                chmax(dp[p[i]], dp[p[i+1]]);
            }
        }
        int mx = 0;
        rep(i, 0, n) chmax(mx, dp[i]);
        cout << n-mx << endl;
    }
    return 0;
}