#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

/*
単一始点最短経路問題
*/

vector<vector<pii>> g(105);
vector<int> dist(105, 1<<30);
void dijk(){
    priority_queue<pii, vector<pii>, greater<pii>> que;
    que.push(make_pair(0, 0));
    dist[0] = 0;
    while(!que.empty()){
        pii q = que.top(); que.pop();
        for(auto nq: g[q.second]){
            if(dist[nq.second] > dist[q.second]+nq.first){
                dist[nq.second] = dist[q.second]+nq.first;
                que.push(make_pair(dist[nq.second], nq.second));
            }
        }
    }
}

int main(){
    int n; cin >> n;
    rep(i, 0, n){
        int id, k; cin >> id >> k;
        rep(j, 0, k){
            int v, c; cin >> v >> c;
            g[i].push_back(make_pair(c, v));
        }
    }

    dijk();
    rep(i, 0, n){
        printf("%d %d\n", i, dist[i]);
    }
}