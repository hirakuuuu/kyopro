#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

int main(){
    int n; cin >> n;
    int a, b; cin >> a >> b;
    a--, b--;
    int m; cin >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> dist(n, -1);
    dist[a] = 0;
    queue<int> que;
    que.push(a);
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(dist[nq] != -1) continue;
            dist[nq] = dist[q]+1;
            que.push(nq);
        }
    }
    vector<ll> cnt(n);
    cnt[a] = 1;
    vector<vector<int>> v(n);
    rep(i, 0, n){
        v[dist[i]].push_back(i);
    }
    rep(i, 1, n){
        for(auto nxt: v[i]){
            for(auto adj: g[nxt]){
                if(dist[adj] == i-1){
                    cnt[nxt] += cnt[adj];
                    cnt[nxt] %= MOD;
                }
            }
        }
    }
    cout << cnt[b] << endl;
    
    return 0;
}