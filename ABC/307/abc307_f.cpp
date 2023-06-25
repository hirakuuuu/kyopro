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
// https://atcoder.jp/contests/abc307/tasks/abc307_f

int main(){
    int n, m; cin >> n >> m;
    vector<vector<pii>> g(n);
    rep(i, 0, m){
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    int k; cin >> k;
    vector<int> ans(n, -1);
    rep(i, 0, k){
        int a; cin >> a;
        a--;
        ans[a] = 0;
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq, pq2;
    rep(i, 0, n){
        if(ans[i] == 0){
            for(auto ni: g[i]){
                if(ans[ni.second] < 0) pq.push(ni);
            }
        }
    }
    int d; cin >> d;
    rep(i, 0, d){
        int x; cin >> x;
        while(!pq.empty()){
            pii p = pq.top();
            if(p.first > x) break;
            pq.pop();
            if(ans[p.second] >= 0) continue;
            pq2.push(p);
        }

        while(!pq2.empty()){
            pii p = pq2.top(); pq2.pop();
            if(ans[p.second] >= 0) continue;
            ans[p.second] = i+1;
            for(auto np: g[p.second]){
                if(p.first+np.first <= x) pq2.push({p.first+np.first, np.second});
                else pq.push(np);
            }
        }
    }

    rep(i, 0, n) cout << ans[i] << endl;
    
    return 0;
}