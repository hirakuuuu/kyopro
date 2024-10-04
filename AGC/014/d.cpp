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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
与えられた木に完全マッチングが存在することと、後手必勝であることが同値
- 1, 2 の場合は明らか、偶奇を分けて帰納法をする
- 葉である頂点が2つ以上ある頂点があれば、先手必勝
- そうで無い場合は、頂点数を減らせるので帰納法の仮定が使える

木の最大マッチングは貪欲法で解ける. 
*/


int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);

    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if(n%2){
        cout << "First" << endl;
        return 0;
    }

    vector<int> used(n);
    auto dfs = [&](auto self, int pos, int pre) -> void {
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
        }
        if(pre == -1 || used[pre] || used[pos]) return;
        used[pos] = used[pre] = 1;
    };
    dfs(dfs, 0, -1);

    rep(i, 0, n){
        if(!used[i]){
            cout << "First" << endl;
            return 0;
        }
    }
    cout << "Second" << endl;

    return 0;
}