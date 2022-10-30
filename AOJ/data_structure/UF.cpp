#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

struct UnionFind {
    // 親の配列
    vector<int> par;

    // 親は-1で初期化
    UnionFind(int n): par(n) {
        rep(i, 0, n) par[i] = -1;
    }
    
    // ｘの根を求める
    int root(int x){
        // 親が負ならreturn
        if(par[x] < 0) return x;
        // 経路圧縮
        return par[x] = root(par[x]);
    }

    // 同じ集団に属しているかを調べる
    bool same(int x, int y){
        // 根が一致しているかどうかで判断
        return root(x) == root(y);
    }

    // xが属する集団とyが属する集団を繋げる
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        // そもそも同じなら何もしない
        if(x == y) return;
        // 集団のサイズが大きい方の集合を優先する
        if(par[x] < par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }

    // xが属する集合のサイズを求める
    int size(int x){
        x = root(x);
        // 根の親に-1を掛けたものが集合のサイズ
        return par[x]*(-1);
    }
};


int main(){
    int n, q; cin >> n >> q;
    UnionFind tree(n);
    vector<int> ans;
    while(q--){
        int com, u, v; cin >> com >> u >> v;
        if(com == 0){
            tree.unite(u, v);
        }else{
            if(tree.same(u, v)) ans.push_back(1);
            else ans.push_back(0);
        }
    }
    for(auto aa: ans) cout << aa << endl;
    return 0;
}