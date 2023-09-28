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
// https://atcoder.jp/contests/abc267/tasks/abc267_f

vector<int> tmp;
vector<int> ans(200005, -1);
void dfs(int pos, int pre, vector<vector<int>> &g, vector<vector<pair<int, int>>> &queri){
    for(auto q: queri[pos]){
        auto [k, i] = q;
        if(tmp.size() < k) continue;
        ans[i] = tmp[tmp.size()-k]+1;
    }
    tmp.push_back(pos);
    for(auto npos: g[pos]){
        if(npos == pre) continue;
        dfs(npos, pos, g, queri);
    }
    tmp.pop_back();
}

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int q; cin >> q;
    vector<vector<pair<int, int>>> queri(n);
    rep(i, 0, q){
        int u, k; cin >> u >> k;
        u--;
        queri[u].emplace_back(k, i);
    }

    // 直径の端点を求める
    vector<int> dist(n, -1);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    while(!que.empty()){
        int q_ = que.front(); que.pop();
        for(auto nq: g[q_]){
            if(dist[nq] != -1) continue;
            dist[nq] = dist[q_]+1;
            que.push(nq);
        }
    }
    int L = 0;
    rep(i, 1, n){
        if(dist[L] < dist[i]) L = i;
    }

    fill(dist.begin(), dist.end(), -1);
    que.push(L);
    dist[L] = 0;
    while(!que.empty()){
        int q_ = que.front(); que.pop();
        for(auto nq: g[q_]){
            if(dist[nq] != -1) continue;
            dist[nq] = dist[q_]+1;
            que.push(nq);
        }
    }
    int R = 0;
    rep(i, 1, n){
        if(dist[R] < dist[i]) R = i;
    }

    dfs(L, -1, g, queri);
    dfs(R, -1, g, queri);

    rep(i, 0, q){
        cout << ans[i] << '\n';
    }
    return 0;
}