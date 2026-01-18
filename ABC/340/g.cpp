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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<int> c(n);
    rep(i, 0, n) cin >> c[i], c[i]--;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 重心分解（centroid decomposition）
    vector<int> sz(n);    // 部分木のサイズ
    auto get_centroid = [&](int v, int w) { // (v, w) の辺をのぞいて v が属する方の部分木の重心を求める
        vector<pair<int, int>> ps;
        // DFS1：部分木のサイズを求める O(n)
        auto dfs = [&](auto f, int pos, int pre) -> int {
            sz[pos] = 1;
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                sz[pos] += f(f, nxt, pos);
            }
            return sz[pos];
        };
        int total = dfs(dfs, v, w), c = -1;
        // DFS2：重心を求める O(n)
        auto dfs2 = [&](auto f, int pos, int pre) -> void {
            bool ok = (total-sz[pos])*2 <= total;
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                f(f, nxt, pos);
                if(sz[nxt]*2 > total) ok = false;
            }
            if(ok) c = pos;
        };
        dfs2(dfs2, v, w);
        return c;
    };

    auto f = [&](auto self, int pos, int pre) -> map<int, pair<mint, mint>> {
        // int centroid = get_centroid(pos, pre);
        // cout << centroid << endl;
        // cout << pos << endl;
        map<int, pair<mint, mint>> res;
        res[c[pos]] = {1, 1};
        set<int> s;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            for(auto [key, val]: self(self, nxt, pos)){

                auto [cnt1, cnt2] = val; // {部分木の中で合法な木，根に接続するかつ根以外が合法な木}
                res[key].first += cnt1+res[key].second*cnt2;
                if(s.count(key)){
                    if(key != c[pos]) res[key].second += res[key].second*cnt2;
                    else res[key].second += (res[key].second-1)*cnt2;
                }
                res[key].second += cnt2;
                s.insert(key);
            }
        }
        return res;
    };

    int centroid = get_centroid(0, -1);
    map<int, pair<mint, mint>> ans = f(f, centroid, -1);
    mint sum = 0;
    for(auto [key, val]: ans){
        sum += val.first;
    }
    cout << sum.val() << endl;


    
    return 0;
}