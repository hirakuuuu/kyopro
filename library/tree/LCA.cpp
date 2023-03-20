#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const ll INF = (1LL<<60);

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
lowest common ancestor(LCA)とは、根付き木の2つの頂点に対して、
共通祖先(common ancestor)のうち最も深さが深い頂点のこと、またそれを求める問題のことである。 
最小共通祖先, 最小共通先祖, nearest common ancestor, NCA, 最近共通祖先 などとも呼ばれる。

求め方はいくつかあるが、「オイラーツアー」と「区間minセグメント木」を用いた解法を採用。

オイラーツアーは、深さ優先探索で通りかかった順番に頂点を記述する方法。 
n-1辺を行き帰りで2回ずつとおるので、出発点と合わせて長さ2n-1の配列になる。

この変換により、木の祖先・子孫関係を1次元配列で持つことができるため、 
1次元配列で扱える様々なデータ構造を利用できる（BIT、セグメント木など）

LCAを求めるには、オイラーツアーで通りかかった順番に頂点番号と深さを記録していく。 
また、その過程で各頂点が最初に現れた位置も記録していく。 
実際には、最初に現れた位置でなく、最初～最後までのどこかの位置であればよいが、通常は最初に記録しておくのが一番やりやすい。

- eular_tour[i] = (d, v)
  i番目に通りかかる頂点の（深さ, 頂点番号）

- first_appear[v] = i
  頂点vがeular_tour上で初めて現れるindex

こうすると、頂点aとbのLCAは、以下で求められる。

-それぞれが eular_tour 上ではじめて現れるindex pa,pbを取得する。(pa<pbと仮定する)
- euler_tour上で、区間[pa,pb]内から、depthが最小となる頂点を取得する
- そいつがLCAである（このような頂点はただ1つ存在する）

もし、LCAの頂点番号は不要で、深さだけが求められればいい場合、eular_tour で管理するのはdのみでよい。

参考: https://yukicoder.me/wiki/lowest_common_ancestor
      https://ikatakos.com/pot/programming_algorithm/graph_theory/lowest_common_ancestor
*/

// ここから
// 頂点番号は0インデックスだよ
class EularTour {
    vector<vector<ll>> graph;  //グラフの隣接リスト
    vector<ll> eular_tour;     // オイラーツアーの頂点配列
    vector<ll> depth;          // オイラーツアーの各頂点の深さ
    vector<ll> ind;            // 各頂点がオイラーツアー配列の何番目に最初に訪れるか

    public:
        // コンストラクタ
        EularTour(ll n_, vector<vector<ll>> g): depth(n_, 0), ind(n_, 0){
            graph = g;
            dfs();
        }

        // DFS（オイラーツアー構築）
        void dfs(ll now=0, ll par=-1, ll d=0){//今の頂点、親の頂点、今の頂点の深さ
            ind[now] = eular_tour.size();
            depth[now] = d;
            eular_tour.push_back(now);
            for(auto child: graph[now]){
                if(child != par){
                    dfs(child, now, d+1);
                    eular_tour.push_back(now);
                }
            }
        }

        // 深さを取得
        ll get_depth(ll n){
            return depth[n];
        }

        // オイラーツアー配列の何番目に最初に訪れるかを取得
        ll get_ind(ll n){
            return ind[n];
        }

        // 深さと頂点番号のpairを格納した配列を取得
        vector<pll> get_pair_list(){
            vector<pll> res;
            for(auto enode: eular_tour){
                res.push_back(make_pair(depth[enode], enode));
            }
            return res;
        }
};

// 深さと頂点番号を格納した配列から、区間のうち深さが最小の頂点を求める
class MinSegTree {
    ll n;
    vector<pll> node;
    
    public:
        MinSegTree(vector<pll> a_){
            // 配列のサイズを取得
            ll sz = a_.size();
            // nはszを超える最小の2のべき乗
            n = 1LL;
            while(n < sz) n *= 2;
            // ノードの個数は2n-1
            node.resize(2*n-1, {INF, INF});

            // 再下段にaの値を格納
            rep(i, 0, sz) node[i+n-1] = a_[i];
            // 親を更新
            rrep(j, (int)n-2, 0) node[j] = min(node[2*j+1], node[2*j+2]);
        }

        // 更新処理
        void update(ll x, pll val){
            // 再下段の指定した位置の値を更新
            x += n-1;
            chmin(node[x], val);
            // 親の値を更新しながら上る
            while(x > 0){
                x = (x-1)/2;
                chmin(node[x], val);
            }
        }

        // 取得処理
        pll get_min(ll a, ll b, ll k=0, ll l=0, ll r=-1){
            // 最初は右端をnにする
            if(r < 0){
                r = n;
                b++;
            }
            // 区間が範囲に収まっていなければINFを返す
            if(r <= a or b <= l) return {INF, INF};
            // 区間が完全に収まっているならば、最小値を返す
            if(a <= l and r <= b) return node[k];

            // 区間を２つに分けて最小値を求め、小さい方を返す
            pll v1 = get_min(a, b, 2*k+1, l, (l+r)/2);
            pll v2 = get_min(a, b, 2*k+2, (l+r)/2, r);
            return min(v1, v2);
        }
};

class LCA {
    vector<vector<ll>> graph;  //グラフの隣接リスト
    EularTour eular_tour;      // オイラーツアー
    MinSegTree min_seg_tree;   // 区間minセグ木

    public:
        // コンストラクタ
        LCA(ll n_, vector<vector<ll>> g_): 
        eular_tour(n_, g_), 
        min_seg_tree(eular_tour.get_pair_list()){};

        // 頂点aと頂点bのlcaを求める
        ll get_lca(ll a, ll b){
            // a, bがオイラーツアーで最初に現れる位置を取得
            ll pa = eular_tour.get_ind(a);
            ll pb = eular_tour.get_ind(b);
            // pa < pb にする
            if(pa > pb) swap(pa, pb);
            // 区間における深さが最小の点がlca
            return min_seg_tree.get_min(pa, pb).second;
        }
};

// ここまで

int main(){
    ll n; cin >> n;
    vector<vector<ll>> g(n);
    rep(i, 0, n-1){
        ll u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    LCA lca(n, g);

    rep(i, 0, n){
        cout << lca.get_lca(i, n-1) << endl;
    }
    
    return 0;
}