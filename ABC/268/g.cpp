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

struct Trie {
    using MP = unordered_map<char, int>;
    vector<MP> to;  // 辺
    vector<int> cnt; // 各頂点に対応する文字列の個数
    Trie(): to(1), cnt(1) {}

    // 文字列の追加 O(|s|)
    int add(const string & s){
        int v = 0;
        for(char c: s){
            if(!to[v].count(c)){
                to[v][c] = (int)to.size();
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

};

int main(){
    int n; cin >> n;
    vector<int> vid(n);
    Trie t;
    rep(i, 0, n){
        string s; cin >> s;
        vid[i] = t.add(s);
    }
    t.build();

    rep(i, 0, n){
        mint ans = 1;
        ans += (mint(1))*t.anc[vid[i]];
        ans += (mint(1)/2)*(n-1-t.des[vid[i]]-t.anc[vid[i]]);
        cout << ans.val() << endl;
    }
    return 0;
}