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

struct Trie {
    using MP = unordered_map<char, int>;
    vector<MP> to;  // 辺
    vector<int> cnt; // 各頂点に対応する文字列の個数
    vector<int> par;
    vector<int> depth;
    Trie(): to(1), cnt(1), par(1, -1), depth(1) {}

    // 文字列の追加 O(|s|)
    int add(const string & s){
        int v = 0;
        for(char c: s){
            if(!to[v].count(c)){
                to[v][c] = (int)to.size();
                par.push_back(v);
                depth.push_back(depth[v]+1);
                to.push_back(MP());
                cnt.push_back(0);
            }
            v = to[v][c];
        }
        cnt[v]++; // sの分を増やす
        return v; // sに対応する trie 木上での頂点番号を返す
    }

    vector<int> anc, des; // 祖先, 子孫の数
    // trie 木上でのDFS O(|to|)
    int dfs(int v, int num) {
        anc[v] = num; // 祖先の数は num
        for(auto p: to[v]){
            des[v] += dfs(p.second, num+cnt[v]);
        }
        return des[v]+cnt[v];
    }
    // trie 木を作成
    void build() {
        anc = des = vector<int>(to.size());
        dfs(0, 0);
    }

    // v からルートに向かって, それを部分文字列として含む文字列の最小サイズを更新
    vector<int> mi;
    void init_mi(){
        mi = vector<int>(to.size(), IINF);
        mi[0] = 0;
    }
    int query(const string & s){
        int v = 0;
        int res = IINF;
        for(char c: s){
            chmin(res, s.size()+mi[v]-2*depth[v]);
            v = to[v][c];
        }
        chmin(res, s.size()+mi[v]-2*depth[v]);
        // cout << endl;
        return res;
    }
    void mi_up(int v, int sz){
        while(v != -1){
            chmin(mi[v], sz);
            v = par[v];
        }
    }

    void check_mi(){
        rep(i, 0, to.size()){
            cout << depth[i] << ' ';
        }
        cout << endl;
    }

};

int main(){
    int n; cin >> n;
    vector<string> S(n);
    vector<int> vid(n);
    Trie t;
    rep(i, 0, n){
        cin >> S[i];
        vid[i] = t.add(S[i]);
        // cout << t.depth[vid[i]] << ' ';
    }
    // cout << endl;

    t.build();
    t.init_mi();
    rep(i, 0, n){
        cout << t.query(S[i]) << endl;
        t.mi_up(vid[i], S[i].size());
        // t.check_mi();
    }


    
    return 0;
}