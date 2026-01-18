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
    int h, w; cin >> h >> w;
    vector<int> a(h);
    rep(i, 0, h){
        rep(j, 0, w){
            char c; cin >> c;
            a[i] = a[i]*2+(c-'0');
        }
    }

    // dp[i][j] := a == i を満たすような行について， pc(a^i) の値が j であるものの個数
    vector<vector<int>> dp(1<<w, vector<int>(w+1));
    rep(i, 0, h) dp[a[i]][0]++;

    // 下のけたから順に条件を緩和していく
    rep(i, 0, w){
        vector<vector<int>> ndp(1<<w, vector<int>(w+1));
        rep(j, 0, 1<<w){
            rep(k, 0, w+1){
                ndp[j][k] += dp[j][k];
                if(k > 0) ndp[j][k] += dp[(j^(1<<i))][k-1];
            }
        }
        swap(dp, ndp);
    }

    int ans = h*w;
    rep(i, 0, 1<<w){
        int tmp = 0;
        rep(j, 0, w+1) tmp += dp[i][j]*min(j, w-j);
        chmin(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}