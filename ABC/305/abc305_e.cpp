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
// https://atcoder.jp/contests/abc305/tasks/abc305_e



int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n+1);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    priority_queue<pii> que;
    vector<bool> seen(n+1);
    vector<int> hp(n+1, -1);
    rep(i, 0, k){
        int p, h; cin >> p >> h;
        que.push({h, p});
        hp[p] = h;
    }
    
    
    while(!que.empty()){
        pii q = que.top(); que.pop();
        seen[q.second] = true;
        for(auto nq: g[q.second]){
            if(seen[nq] || q.first < 1) continue;
            if(hp[nq] >= q.first-1) continue;
            hp[nq] = q.first-1;
            que.push({q.first-1, nq});
        }
    }
    vector<int> ans;
    rep(i, 1, n+1){
        if(seen[i]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(auto aa: ans) cout << aa << ' ';
    cout << endl;
    
    
    return 0;
}