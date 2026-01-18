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

// https://atcoder.jp/contests/arc116/submissions/21356656
// こたつがめさんの提出を読んで理解した

/*
- 木上の terminal monitering set を求める問題
- 距離を決めると最小個数が木DPで求まる
- 各部分木の根について，（覆われてるなら残りどこまで覆えるか）または（覆われてないならどこまで覆わなければならないか）を表す数を計算
- 覆われてないかつ，他の部分木からも覆えないかつ，距離がこれ以上伸ばせないとなったらその時見ている根を使うのが最適

*/

int main(){
    int n, k; cin >> n >> k;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ng = 0, ok = n;
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        int cnt = 0;
        auto f = [&](auto self, int pos, int pre) -> int {
            int l = 0, r = 0;
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                int res = self(self, nxt, pos);
                chmin(l, res);
                chmax(r, res);
            }
            if(l < 0){
                if(l+r < 0) return l+1; // l+r < 0 は距離 l までは被覆できる特別な頂点が， rの頂点も被覆できることを意味する
                else if(r == mid){
                    cnt++;
                    return -mid;
                }else{
                    return r+1;
                }
            }else{
                if(r == mid){
                    cnt++;
                    return -mid;
                }else{
                    return r+1;
                }
            }
        };
        int res = f(f, 0, -1);
        if(res > 0) cnt++;
        if(cnt <= k) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    
    return 0;
}