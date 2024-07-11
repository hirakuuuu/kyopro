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
全部の頂点について, 次数 -1 くらいのアンテナが必要
次数が3以上の頂点を根として木DP
ボトムアップで必要な分だけ追加していくので正当性がある。

*/

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int root = -1;
    rep(i, 0, n){
        if(g[i].size() >= 3) root = i;
    }
    if(root == -1){
        cout << 1 << endl;
        return 0;
    }

    auto dfs = [&](auto self, int pos, int pre) -> int {
        int cnt = 0, sum = 0;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            int res = self(self, nxt, pos);
            if(res == 0) cnt++;
            sum += res;
        }
        if(cnt) return sum+cnt-1;
        return sum;
    };
    cout << dfs(dfs, root, -1) << endl;
    
    return 0;
}