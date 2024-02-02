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
// https://atcoder.jp/contests/arc117/tasks/arc117_d

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto get_far_i = [&](int s) -> int {
        queue<int> que;
        que.push(s);
        vector<int> dist(n, -1);
        dist[s] = 0;
        int far_i = s, max_d = 0;
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto nq: g[q]){
                if(dist[nq] != -1) continue;
                dist[nq] = dist[q]+1;
                if(dist[nq] > max_d){
                    max_d = dist[nq];
                    far_i = nq;
                }
                que.push(nq);
            }
        }
        return far_i;
    };
    int s = get_far_i(0);

    vector<int> depth(n);
    depth[s] = 0;
    auto dfs1 = [&](auto sfs, int pos, int pre) -> int {
        rep(i, 0, g[pos].size()){
            int nxt = g[pos][i];
            if(nxt == pre) continue;
            chmax(depth[pos], sfs(sfs, nxt, pos));
        }
        return depth[pos]+1;
    };
    dfs1(dfs1, s, -1);

    vector<int> e(n);
    int tmp = 1;
    auto dfs2 = [&](auto sfs, int pos, int pre, int &tmp) -> void {
        e[pos] = tmp;
        sort(g[pos].begin(), g[pos].end(), [&](int a, int b){
            return depth[a] < depth[b];
        });
        rep(i, 0, g[pos].size()){
            int nxt = g[pos][i];
            if(nxt == pre) continue;
            tmp++;
            sfs(sfs, nxt, pos, tmp);
            tmp++;
        }
    };

    dfs2(dfs2, s, -1, tmp);
    rep(i, 0, n){
        cout << e[i] << ' ';
    }
    cout << endl;

    return 0;
}