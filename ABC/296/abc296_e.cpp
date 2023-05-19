#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(ll i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc296/tasks/abc296_e

struct StronglyConnectedComponents {

private:

    int n; // 頂点の数
    vector<vector<int>> g; // グラフの隣接リスト
    vector<vector<int>> g_reverse; // 辺の向きを逆にしたグラフの隣接リスト
    vector<vector<int>> components; // 成分のリスト
    vector<int> postorder; // 帰りがけ順に記録するリスト
    vector<bool> seen; // 探索済みかどうかを記録

    // 帰りがけ順を求めるためのDFS
    void dfs_for_postorder(int s){
        seen[s] = true;
        for(auto ns: g[s]){
            if(seen[ns]) continue;
            dfs_for_postorder(ns);
        }
        postorder.push_back(s);
    }

    // 成分を取得するためのDFS
    void dfs_for_components(int s){
        if(seen[s]) return;
        seen[s] = true;
        for(auto ns: g_reverse[s]){
            if(seen[ns]) continue;
            dfs_for_components(ns);
        }
        components.back().push_back(s);
    }

    // 探索のリセット
    void reset(){
        fill(seen.begin(), seen.end(), false);
    }
    
public:

    // コンストラクタ
    StronglyConnectedComponents(const vector<vector<int>> &g_) : g(g_) {
        n = (int)g.size();
        seen.resize(n);
        g_reverse.resize(n);
        rep(i, 0, n){
            for(auto j: g[i]){
                g_reverse[j].push_back(i); // 辺 i→j を j→i に変換
             }
        }
    }

    // 分解操作
    vector<vector<int>> decomposition() {
        // 探索の状態をリセット
        reset();
        // 帰りがけ順を求めるためのDFS
        rep(i, 0, n){ // 連結で無い場合を考慮してループにする
            if(seen[i]) continue;
            dfs_for_postorder(i);
        }

        // 帰りがけ順の後ろから探索するので、配列を反転
        reverse(postorder.begin(), postorder.end());

        // 探索の状態をリセット
        reset();
        // 分解のためのDFS
        for(auto node: postorder){
            if(seen[node]) continue; // 探索済みならスキップ
            components.push_back({}); // 配列を追加
            dfs_for_components(node);
        }

        return components;
    }

};


int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i]; a[i]--;
    }

    vector<vector<int>> g(n);
    rep(i, 0, n) g[i].push_back(a[i]);

    int ans = 0;
    StronglyConnectedComponents scc(g);
    vector<vector<int>> components = scc.decomposition();
    for(auto component: components){
        if(component.size() > 1){
            ans += component.size();
        }else{
            int c = component[0];
            if(c == a[c]) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}