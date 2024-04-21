#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
二乗の木DPについて
https://snuke.hatenablog.com/entry/2019/01/15/211812
木DPにおいて、結果を配列で持つとき、マージするのにO(N^2)、全体でO(N^3)かかりそうに見えるが、
解析してみると実はO(N^2)になる.

例
- ２つの頂点集合をマージして、張られていない辺を追加していく
- 集合 A, B をマージするとき、O(|A||B|) かかる
- しかし, 全体では完全グラフの辺の本数しか張られないので、O(N^2)でおさまる

実装では、配列のサイズを小さい状態に抑えておいて、必要になったら増やすようにするのがよさそう

*/

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // vector<vector<vector<mint>>> cnt(2, vector<vector<mint>>(n, vector<mint>(n+1)));
    auto dfs = [&](auto self, int pos, int pre) -> vector<vector<mint>> {
        // cnt[0][pos][1] = 1;
        // cnt[1][pos][0] = 1;
        vector<vector<mint>> res(2, vector<mint>(2));
        res[0][1] = 1;
        res[1][0] = 1;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            vector<vector<mint>> ch = self(self, nxt, pos);
            vector<vector<mint>> dp(2, vector<mint>(res[1].size()+ch[1].size()+1));
            rep(i, 0, res[1].size()){
                rep(j, 0, ch[1].size()){
                    dp[0][i+j] += res[0][i]*ch[1][j];
                    if(i+j > 0) dp[0][i+j-1] += res[0][i]*ch[0][j];
                    dp[1][i+j] += res[1][i]*(ch[0][j]+ch[1][j]);
                }
            }
            swap(res, dp);
        }
        return res;
    };
    vector<vector<mint>> ans = dfs(dfs, 0, -1);
    rep(i, 1, n+1){
        cout << (ans[0][i]+ans[1][i]).val() << endl;
    }

    return 0;
}