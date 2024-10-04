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
木の最大マッチングは葉から貪欲法で解ける. 
*/


// verify: https://atcoder.jp/contests/agc014/tasks/agc014_d
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

    vector<pair<int, int>> matching;
    {
        vector<int> used(n);
        auto dfs = [&](auto self, int pos, int pre) -> void {
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                self(self, nxt, pos);
            }
            if(pre == -1 || used[pre] || used[pos]) return;
            used[pos] = used[pre] = 1;
            matching.push_back({pos, pre});
        };
        dfs(dfs, 0, -1);
    }

    // 完全マッチングが存在するかどうかで判定
    if(matching.size() == n/2) cout << "Second" << endl;
    else cout << "First" << endl;

    return 0;
}