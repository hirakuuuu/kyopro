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
    int m; cin >> m;
    vector<vector<int>> g(9);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> p(9, 8);
    rep(i, 0, 8){
        int pos; cin >> pos;
        pos--;
        p[pos] = i;
    }

    map<vector<int>, int> dist;
    dist[p] = 0;
    queue<vector<int>> que;
    que.push(p);
    while(!que.empty()){
        vector<int> q = que.front(); que.pop();
        // cout << dist[q] << ' ';
        // rep(i, 0, 9){
        //     cout << q[i] << ' ';
        // }
        // cout << endl;
        int pos = -1, tmp = dist[q];
        rep(j, 0, 9){
            if(q[j] == 8){
                pos = j;
                break;
            }
        }
        for(auto adj: g[pos]){
            swap(q[adj], q[pos]);
            if(dist.find(q) != dist.end()){
                swap(q[adj], q[pos]);
                continue;
            }
            dist[q] = tmp+1;
            que.push(q);
            swap(q[adj], q[pos]);
        }
    }
    vector<int> ord(9);
    iota(ord.begin(), ord.end(), 0);
    if(dist.find(ord) != dist.end()) cout << dist[ord] << endl;
    else cout << -1 << endl;

    
    return 0;
}