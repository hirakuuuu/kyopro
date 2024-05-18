#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
木DPに慣れよう
- aのみ, bのみ, ab両方 の３状態がある
- ボトムアップで求めるにはどうすればよいか
- 辺を削除するとき、その部分木ではabが両方含まれていないといけない

*/


int main(){
    int n; cin >> n;
    vector<char> c(n);
    rep(i, 0, n) cin >> c[i];
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<vector<mint>> dp(n, vector<mint>(3));
    auto dfs = [&](auto self, int pos, int pre) -> void{
        int tmp = c[pos]-'a';
        dp[pos][tmp] = dp[pos][2] = 1;
        bool f = false;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            f = true;
            self(self, nxt, pos);
            dp[pos][tmp] *= dp[nxt][tmp]+dp[nxt][2];
            dp[pos][2] *= dp[nxt][0]+dp[nxt][1]+2*dp[nxt][2];
        }
        if(!f) dp[pos][2] = 0;
        else dp[pos][2] -= dp[pos][tmp];
    };
    dfs(dfs, 0, -1);
    cout << dp[0][2].val() << endl;


    return 0;
}