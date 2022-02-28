#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

/*
関節点：無向グラフにおいて頂点uと、uから出ている全てのエッジを削除して得られる部分グラフが、
       非連結になるとき、頂点uをグラフＧの関節点または切断点という

関節点を求めるアルゴリズム
1．適当な一つの頂点から深さ優先探索をして各頂点に対して次の値を求める
・prenum[u]: uを訪問した順番
・parent[u]: DFSによって生成される木(DFS Tree)におけるuの親
・lowest[u]: 次の3つの値の最小値
            1. prenum[u]
            2. GのBackedge(u, v) が存在するとき、prenum[v]
            (Backedge(u, v) は頂点ｕからＴに属する頂点ｖに向かうＴに属さないＧのエッジ)
            3. Ｔに属する頂点ｕの全ての子ｘに対するlowest[x]

2. 1で求めた値により関節点が以下のように決定される
・Ｔのルートｒが2つ以上の子どもを持つとき、ｒは関節点
・各頂点ｕにおいて、ｕの親parent[u]をｐとすると、prenum[p]<=lowest[u]ならば、ｐは関節点
（これは頂点ｕ、Ｔにおけるｕの子孫から頂点ｐの祖先へのエッジがないことを示す）
*/

vector<vector<int>> g(100005);
vector<int> prenum(100005);
vector<int> lowest(100005);
vector<int> parent(100005, -1);
vector<int> visited(100005);

// 何番目に訪れたか
int cnt = 1;
// DFS
void dfs(int pos, int pre){
    // lowestとprenumに値を代入
    lowest[pos] = prenum[pos] = cnt;
    // 順番を進める
    cnt++;
    // すでに訪れたことを記録
    visited[pos] = 1;
    // 子に対する操作
    for(auto npos: g[pos]){
        // まだ訪れていない頂点について
        if(visited[npos] == 0){
            // 親を記録
            parent[npos] = pos;
            // DFS
            dfs(npos, pos);
            // lowestの更新
            lowest[pos] = min(lowest[pos], lowest[npos]);
        // すでに訪れている頂点で直前の頂点と異なるものに対する処理(Backedgeが存在する場合)
        }else if(npos != pre){
            // lowestの更新
            lowest[pos] = min(lowest[pos], prenum[npos]);
        }
    }
}

void art_point(int v){
    dfs(0, -1);
    set<int> ap;
    int rc = 0;
    rep(i, 1, v){
        int p = parent[i];
        if(p == 0) rc++;
        else if(prenum[p] <= lowest[i]) ap.insert(p);
    }
    if(rc >= 2) ap.insert(0);
    for(auto itr = ap.begin(); itr != ap.end(); ++itr){
        cout << *itr << endl;
    }
}


int main(){
    int v, e; cin >> v >> e;
    rep(i, 0, e){
        int s, t; cin >> s >> t;
        g[s].push_back(t);
        g[t].push_back(s);
    }
    art_point(v);
}