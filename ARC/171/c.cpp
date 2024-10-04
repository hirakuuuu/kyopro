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
操作する辺の集合が異なると、最終的に得られる数列も異なる
また、各頂点について、操作する辺の順番の相対順序が一致していれば、最終的に得られる数列が一致する
さらに、操作する辺の順番を各頂点について定めたとき、それに対応するような操作例が必ず存在する
*/

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto dfs = [&](auto self, int pos, int pre) -> vector<mint> {
        vector<mint> res;
        res.push_back(1);

        for(auto nxt: g[pos]){
            if(nxt == pre) continue;

            vector<mint> tmp = self(self, nxt, pos);

            vector<mint> res_(res.size()+1);

            rep(i, 0, res.size()){
                rep(j, 0, tmp.size()){
                    res_[i] += res[i]*tmp[j];
                    res_[i+1] += res[i]*tmp[j]*(i+1)*(j+1);
                }
            }
            
            swap(res, res_);
        }
        return res;
    };
    vector<mint> cnt = dfs(dfs, 0, -1);
    mint ans = 0;
    rep(i, 0, cnt.size()) ans += cnt[i];
    cout << ans.val() << endl;


    
    return 0;
}