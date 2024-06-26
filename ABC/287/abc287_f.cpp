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
    auto dfs = [&](auto self, int pos, int pre) -> pair<vector<mint>, vector<mint>> {
        // cnt[0][pos][1] = 1;
        // cnt[1][pos][0] = 1;
        vector<mint> res1(2), res2(1);
        res1[1] = 1;
        res2[0] = 1;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            auto [cnt1, cnt2] = self(self, nxt, pos);

            vector<mint> cnt3 = cnt2;
            while(cnt3.size() < cnt1.size()-1) cnt3.push_back(0);
            rep(i, 0, cnt1.size()-1){
                cnt3[i] += cnt1[i+1];
            }
            vector<mint> sum = convolution(res1, cnt3);
            while(res1.size() < sum.size()) res1.push_back(0);
            rep(i, 0, sum.size()) res1[i] += sum[i];

            vector<mint> cnt4 = cnt1;
            while(cnt4.size() < cnt2.size()) cnt4.push_back(0);
            rep(i, 0, cnt2.size()) cnt4[i] += cnt2[i];
            sum = convolution(res2, cnt4);
            while(res2.size() < sum.size()) res2.push_back(0);
            rep(i, 0, sum.size()) res2[i] += sum[i];
        }
        res2[0]--;
        return {res1, res2};
    };
    auto [ans1, ans2] = dfs(dfs, 0, -1);
    while(ans1.size() <= n) ans1.push_back(0);
    while(ans2.size() <= n) ans2.push_back(0);
    rep(i, 1, n+1){
        cout << (ans1[i]+ans2[i]).val() << endl;
    }

    return 0;
}