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
    vector<int> a(n);
    vector<vector<int>> p(20);
    rep(i, 0, n){
        cin >> a[i], a[i]--;
        p[a[i]].push_back(i);
    }

    vector<int> dp(1<<20, n);
    dp[0] = -1;
    rep(i, 1, 1<<20){
        rep(j, 0, 20){
            if((i>>j)&1){
                int l = dp[i-(1<<j)];
                auto itr = upper_bound(p[j].begin(), p[j].end(), l);
                if(itr != p[j].end() && next(itr) != p[j].end()){
                    chmin(dp[i], *next(itr));
                }
            }
        }
    }
    int ans = 0;
    rep(i, 1, 1<<20){
        if(dp[i] == n) continue;
        chmax(ans, 2*__popcount(i));
    }
    cout << ans << endl;
    
    return 0;
}