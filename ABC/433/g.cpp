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
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
- suffix_array と lcp_array があるといろいろできる
    - lcp_array は suffix_array の隣接する接尾辞の共通接頭辞の長さ
- 今回の問題だと，suffix_tree 上で木 DP をしたい気持ちになる
- suffix_array は suffix_tree の行きがけ順に対応するので，頂点をたどる操作を lcp_array の値を踏まえたうえで再現するとうまく構築可能
*/

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = (int)s.size();

        vector<int> sa = suffix_array(s);
        vector<int> lcp = lcp_array(s, sa);

        vector<vector<int>> g(1);
        vector<int> par(1, -1), depth(1);
        {
            int v = 0;
            rep(i, 0, n){
                int d = n-sa[i];
                if(depth[v] < d){
                    int u = (int)g.size();
                    g.push_back({});
                    par.push_back(v);
                    depth.push_back(d);
                    g[v].push_back(u);
                    v = u;
                }
            
                if(i == n-1) break;

                d = lcp[i];
                while(d < depth[v]) v = par[v];
                if(d > depth[v]){
                    int u = (int)g.size();
                    g.push_back({});
                    par.push_back(v);
                    depth.push_back(d);
                    par[g[v].back()] = u;
                    g[u].push_back(g[v].back());
                    g[v].back() = u;
                    v = u;
                }
            }
        }

        auto f = [&](auto self, int pos) -> int {
            int res = 0;
            for(auto nxt: g[pos]){
                int l = (depth[nxt]-depth[pos])%2;
                if(self(self, nxt)^l) res = 1;
            }
            return res;
        };
        if(f(f, 0)){
            cout << "Alice" << endl;
        }else{
            cout << "Bob" << endl;
        }
    }
    return 0;
}