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
// https://atcoder.jp/contests/pakencamp-2023-day2/tasks/b

int main(){
    int n, m, s; cin >> n >> m >> s;
    s--;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> need1(n), need2(n);
    need1[0] = 1;
    need2[s] = 1;
    rep(i, 0, m){
        int x; cin >> x; x--;
        need1[x] = 1;
    }
    rep(i, 0, m){
        int y; cin >> y; y--;
        need2[y] = 1;
    }

    auto solve = [&](int start, vector<int> need)->vector<int>{
        vector<int> ans(n), cnt(n), dep(n);
        auto dfs1 = [&](auto self, int pos, int pre)-> void {
            if(need[pos]) cnt[pos]++;
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                self(self, nxt, pos);
                cnt[pos] += cnt[nxt];
            }
        };
        auto dfs2 = [&](auto self, int pos, int pre, int d)-> void {
            dep[pos] = d;
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                self(self, nxt, pos, d+(cnt[nxt] == 0 ? 1 : -1));
            }
        };
        dfs1(dfs1, start, -1);
        dfs2(dfs2, start, -1, 0);
        int base = -2;
        rep(i, 0, n) if(cnt[i] > 0) base += 2;
        rep(i, 0, n) ans[i] = base+dep[i];
        return ans;
    };
    vector<int> l1 = solve(0, need1), l2 = solve(s, need2);
    int ans = IINF;
    rep(i, 0, n) chmin(ans, l1[i]+l2[i]);
    cout << ans << endl;


    return 0;
}