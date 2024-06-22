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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<ll> V(n+1), W(n+1);
    rep(i, 1, n+1) cin >> V[i] >> W[i];
    int lim = 1<<10;
    vector<vector<ll>> dp(lim, vector<ll>(100001));
    rep(i, W[1], 100001) dp[1][i] = V[1];
    rep(i, 2, lim){
        if(i > n) break;
        rep(j, 1, 100001){
            dp[i][j] = max(dp[i/2][j], dp[i][j-1]);
            if(j-W[i] >= 0) chmax(dp[i][j], dp[i/2][j-W[i]]+V[i]);
        }
    }

    int q; cin >> q;
    while(q--){
        int v, l; cin >> v >> l;
        if(v < lim){
            cout << dp[v][l] << endl;
            continue;
        }

        vector<ll> cur;
        int len = 0, tmp = v;
        while(tmp >= lim){
            cur.push_back(tmp);
            len++;
            tmp >>= 1;
        }
        ll ans = 0;
        rep(i, 0, 1<<len){
            ll sum_v = 0, sum_w = 0;
            rep(j, 0, len){
                if((i>>j)&1){
                    sum_v += V[cur[j]];
                    sum_w += W[cur[j]];
                }
            }
            if(sum_w > l) continue;
            chmax(ans, sum_v+dp[tmp][l-sum_w]);
        }
        cout << ans << endl;
    }
    
    return 0;
}