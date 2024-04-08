#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

int main(){
    int n; cin >> n;
    vector<int> deg(n);
    vector<vector<int>> g(n);
    map<pair<int, int>, int> id;
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
        id[{a, b}] = id[{b, a}] = i;
    }
    int ans = 0;
    rep(i, 0, n) chmax(ans, deg[i]);
    cout << ans << endl;
    vector<int> c(n-1);
    auto dfs = [&](auto self, int pos, int pre, int ng) -> void {
        if(pre != -1) c[id[{pos, pre}]] = ng;
        int tmp = 1;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            if(tmp == ng) tmp++;
            self(self, nxt, pos, tmp);
            tmp++;
        }
    };
    dfs(dfs, 0, -1, -1);
    rep(i, 0, n-1){
        cout << c[i] << endl;
    }

    return 0;
}