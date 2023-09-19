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
// https://atcoder.jp/contests/abc292/tasks/abc292_e

int main(){
    int n, m; cin >> n >> m;
    vector<vector<bool>> edge(n, vector<bool>(n));
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        edge[u][v] = true;
        g[u].push_back(v);
    }

    vector<int> cnt(n), seen(n);
    queue<int> que;
    rep(i, 0, n){
        fill(seen.begin(), seen.end(), 0);
        que.push(i);
        seen[i] = 1;
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto nq: g[q]){
                if(seen[nq]) continue;
                seen[nq] = true;
                cnt[i]++;
                que.push(nq);
            }
        }
    }

    int ans = 0;
    rep(i, 0, n){
        if(cnt[i]-g[i].size() > 0) ans += cnt[i]-g[i].size();
    }
    cout << ans << endl;
    
    return 0;
}