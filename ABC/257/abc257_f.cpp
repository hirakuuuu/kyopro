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
// https://atcoder.jp/contests/abc257/tasks/abc257_f

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n+1);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dist1(n+1, 1001001001);
    dist1[1] = 0;
    queue<int> que;
    que.push(1);
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(nq == 0 || dist1[nq] != 1001001001) continue;
            dist1[nq] = dist1[q]+1;
            que.push(nq);
        }
    }
    vector<int> distn(n+1, 1001001001);
    distn[n] = 0;
    que.push(n);
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(nq == 0 || distn[nq] != 1001001001) continue;
            distn[nq] = distn[q]+1;
            que.push(nq);
        }
    }

    for(auto n0: g[0]){
        chmin(dist1[0], dist1[n0]+1);
        chmin(distn[0], distn[n0]+1);
    }


    rep(i, 1, n+1){
        int tmp = dist1[n];
        int d1 = min(dist1[i], dist1[0]);
        int dn = min(distn[i], distn[0]);
        chmin(tmp, d1+dn);
        if(tmp == 1001001001) cout << -1 << ' ';
        else cout << tmp << ' ';
    }
    cout << endl;
    
    return 0;
}