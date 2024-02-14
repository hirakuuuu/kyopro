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
    vector<int> p(n);
    vector<vector<int>> g(n);
    rep(i, 1, n){
        cin >> p[i];
        p[i]--;
        g[p[i]].push_back(i);
    }   
    vector<int> depth(n);
    vector<int> pr(n), po(n);
    vector<vector<int>> pre(n);
    vector<vector<int>> post(n);
    int tmp = 0;
    auto dfs = [&](auto sfs, int pos, int d) -> void {
        depth[pos] = d;
        pr[pos] = tmp;
        pre[d].push_back(tmp);
        tmp++;
        for(auto nxt: g[pos]){
            sfs(sfs, nxt, d+1);
        }
        po[pos] = tmp;
        post[d].push_back(tmp);
        tmp++;
    };
    dfs(dfs, 0, 0);

    int q; cin >> q;
    rep(i, 0, q){
        int u, d; cin >> u >> d;
        u--;
        if(depth[u] > d){
            cout << 0 << endl;
            continue;
        }
        if(depth[u] == d){
            cout << 1 << endl;
            continue;
        }
        int l = lower_bound(pre[d].begin(), pre[d].end(), pr[u])-pre[d].begin();
        int r = lower_bound(post[d].begin(), post[d].end(), po[u])-post[d].begin();
        cout << r-l << endl;
    }
    
    return 0;
}