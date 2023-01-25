#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc280/tasks/abc280_f

/*
メモ
- クエリ先読み？
- 道路は向きによってコストが変わるが、実質無向グラフなので、連結であれば到達可能
- 連結でなければ "nan"
- 連結であるとして、連結であるグループにコストが0でない閉路があれば、無限にポイントを増やせる（コストが負でも逆順にたどれば正にできる）
- 連結である頂点にコストが0でない閉路を構成するものがあれば "inf
- 以下閉路はないものとして考える
- 値から頂点へのコストは一意に定まるので、BFS等で求めれば良い

そもそも連結じゃないなら nan
連結かつ連結な頂点でコストが０でない閉路が構成されるなら inf
それ以外なら、連結な頂点間のコストは一意に定まるので、-dist(V, x)+dist(V, y) を出力（distは閉路検出と同時にBFS）

「コストが０でない閉路が存在する」⇔「頂点Vからのコストが一意でない頂点が存在する」に気づけなかった。解説AC
*/

vector<vector<pll>> g(100005);
class UnionFind {
    vector<ll> parent, maxi, mini;
    inline ll root(ll n){
        return (parent[n] < 0? n:parent[n] = root(parent[n]));
    }
public:
    UnionFind(ll n_ = 1): parent(n_, -1), maxi(n_), mini(n_){
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }

    inline bool same(ll x, ll y){
        return root(x) == root(y);
    }

    inline void unite(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return;
        if(parent[rx] > parent[ry]) swap(rx, ry);
        parent[rx] += parent[ry];
        parent[ry] = rx;
        maxi[x] = std::max(maxi[x],maxi[y]);
        mini[x] = std::min(mini[x],mini[y]);
    }

    inline ll min(ll x){
        return mini[root(x)];
    }

    inline ll max(int x){
        return mini[root(x)];
    }

    inline ll size(ll x){
        return (-parent[root(x)]);
    }

    inline ll operator[](ll x){
        return root(x);
    }

    inline void print(){
        rep(i, 0, (ll)parent.size()) cout << root(i) << " ";
        cout << endl;
    }

    void clear(){
        rep(i, 0, (ll)parent.size()){
            parent[i] = -1;
        }
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }
};


int main(){
    ll n, m, q; cin >> n >> m >> q;
    UnionFind uf(n);

    rep(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        uf.unite(a, b);
        g[a].push_back({b, c});
        g[b].push_back({a, -c});
    }

    // コストが0でない閉路を含むかどうか
    vector<ll> dist(n, 1LL<<60);
    vector<bool> negative_roop(n);
    rep(i, 0, n){
        if(uf[i] == i){
            queue<int> que;
            dist[i] = 0;
            que.push(i);
            while(!que.empty()){
                int q = que.front(); que.pop();
                for(const auto [nq, cost]: g[q]){
                    if(dist[nq] == (1LL<<60)){
                        dist[nq] = dist[q]+cost;
                        que.push(nq);
                    }else if(dist[nq] != dist[q]+cost){
                        negative_roop[i] = true;
                    }
                }
            }
        }
    }

    while(q--){
        ll x, y; cin >> x >> y;
        x--, y--;
        if(uf[x] != uf[y]){
            cout << "nan" << endl;
        }else if(negative_roop[uf[x]]){
            cout << "inf" << endl;
        }else{
            cout << -dist[x]+dist[y] << endl;
        }
    }
    
    return 0;
}