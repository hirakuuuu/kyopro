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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
Aho-corasick
- 文字列に辞書の中の文字列が部分文字列として含まれるかを判定
- trie 木に，該当する文字列が存在しない場合の遷移を追加することで，オートマトンにするイメージ
*/

struct AhoCorasick {
    struct Node {
        // 子ノード (a-z だけ想定、他はmapでも可)
        array<int, 26> next{};
        int link = -1;               // 失敗遷移
        vector<int> out;             // このノードで終わるパターンのID
        Node() { next.fill(-1); }
    };

    vector<Node> trie;
    AhoCorasick() { trie.emplace_back(); }

    // パターン文字列を追加
    void add_string(const string &s, int id) {
        int v = 0;
        for(char ch: s){
            int c = ch - 'a';
            if(trie[v].next[c] == -1){
                trie[v].next[c] = (int)trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[c];
        }
        trie[v].out.push_back(id);
    }

    // failure link 構築
    void build(){
        queue<int> que;
        // root の子を初期化
        for(int c = 0; c < 26; c++){
            int u = trie[0].next[c];
            if(u != -1){
                trie[u].link = 0;
                que.push(u);
            }else{
                trie[0].next[c] = 0; // 失敗時は root に戻す
            }
        }

        // BFS で failure link を張る
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(int c = 0; c < 26; c++){
                int u = trie[v].next[c];
                if(u != -1){
                    trie[u].link = trie[trie[v].link].next[c];
                    // 出力リンク（失敗遷移先が持っている out も継承）
                    for (int id : trie[trie[u].link].out) {
                        trie[u].out.push_back(id);
                    }
                    que.push(u);
                }else{
                    trie[v].next[c] = trie[trie[v].link].next[c];
                }
            }
        }
    }    

    // テキスト検索
    vector<pair<int,int>> search(const string &text) {
        vector<pair<int,int>> res; // (位置, パターンID)
        int v = 0;
        for (int i = 0; i < (int)text.size(); i++) {
            int c = text[i] - 'a';
            v = trie[v].next[c];
            for (int id : trie[v].out) {
                res.emplace_back(i, id); 
                // i はパターンの終端位置（開始位置は i - len + 1）
            }
        }
        return res;
    }
};

// verify: https://atcoder.jp/contests/abc419/submissions/68703722
int main(){
    int n, l; cin >> n >> l;
    AhoCorasick ah;
    rep(i, 0, n){
        string s; cin >> s;
        ah.add_string(s, i);
    }
    ah.build();
    int m = (int)ah.trie.size();

    vector<vector<mint>> dp(m, vector<mint>(1<<n));
    dp[0][0] = 1;
    rep(_, 0, l){
        vector<vector<mint>> ndp(m, vector<mint>(1<<n));
        rep(i, 0, m){
            rep(j, 0, 1<<n){
                rep(k, 0, 26){
                    int ni = ah.trie[i].next[k];
                    int nj = j;
                    for(auto bit: ah.trie[ni].out) nj |= 1<<bit;
                    ndp[ni][nj] += dp[i][j];
                }
            }
        }
        swap(dp, ndp);
    }

    mint ans = 0;
    rep(i, 0, m) ans += dp[i][(1<<n)-1];
    cout << ans.val() << endl;

    return 0;
}