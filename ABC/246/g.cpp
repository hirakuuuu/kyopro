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
    rep(i, 1, n) cin >> a[i];
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ok = 0, ng = IINF;
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        // a[i] >= mid の頂点をOKとする. 
        // あるOKの頂点にたどり着くまでの, 子として存在したOKの個数をカウント
        // 深さ < 個数 だったら 高橋勝ち
        vector<int> c(n); // いくつ余裕があるか (負の値があれば高橋勝ち)
        auto dfs1 = [&](auto self, int pos, int pre, int cnt, int depth) -> void {
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                if(a[nxt] >= mid) cnt++;
            }
            c[pos] = depth+1-cnt;
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                self(self, nxt, pos, cnt, depth+1);
            }
        };
        dfs1(dfs1, 0, -1, 0, 0);

        // 一番余裕がないところに遷移する, それが２つ以上あれば余裕を１減らせる
        auto dfs2 = [&](auto self, int pos, int pre, int used) -> bool {
            
            if(c[pos]-used < 0) return true;
            
            int mi = IINF, mi_cnt = 1;
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                if(c[nxt] > mi) continue;
                if(c[nxt] == mi) mi_cnt++;
                else{ mi = c[nxt], mi_cnt = 1; }
            }
            bool res = false;
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                if(c[nxt] == mi) res |= self(self, nxt, pos, used);
                else res |= self(self, nxt, pos, used+1);
            }
            return res;
        };
        if(dfs2(dfs2, 0, -1, 0)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    
    return 0;
}