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

/*
有向グラフのサイクルを検出
ただ、サイクルを検出するだけだと、不要な辺が含まれる可能性がある
しかし、そのサイクルの頂点の部分集合を取れば、条件を満たすサイクルは必ず存在する
よって、頂点数が最小のサイクルを検出すれば良い
これは、色々やり方がある
- 頂点iからBFS、iに辺が伸びている頂点で距離が最小のものを復元
- 入頂点と出頂点を考えた二部グラフのサイクルを考えても問題は変わらない
- 辺に着目して、(a, b) の辺を削除した後、bからaへの最短距離を考える

復元のやり方は距離に従って戻せば良い.
このあたりは慣れておきたい
*/

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(2*n), rev(2*n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b+n);
        g[a+n].push_back(a);
        rev[b+n].push_back(a);
        rev[a].push_back(a+n);
    }
    vector<int> ans;
    int sz = IINF;
    rep(i, 0, n){
        queue<int> que;
        que.push(i);
        vector<int> dist(2*n, -1);
        dist[i] = 0;
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto nq: g[q]){
                if(dist[nq] != -1) continue;
                dist[nq] = dist[q]+1;
                que.push(nq);
            }
        }
        if(dist[i+n] == -1) continue;
        vector<int> tmp;
        int pos = i+n;
        while(pos != i){
            for(auto nxt: rev[pos]){
                if(dist[nxt]+1 == dist[pos]){
                    pos = nxt;
                    break;
                }
            }
            if(pos < n) tmp.push_back(pos);
        }
        if(sz > tmp.size()){
            ans = tmp;
            sz = ans.size();
        }
    }
    if(ans.empty()) cout << -1 << endl;
    else{
        cout << sz << endl;
        for(auto aa: ans){
            cout << aa+1 << endl;
        }
    }

    return 0;

}