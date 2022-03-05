#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

vector<vector<int>> g(105);
vector<int> cnt(105);
vector<int> visited(105, 10005);
void bfs(int a){
    visited[a] = 0;
    cnt[a] = 1;
    queue<int> que;
    que.push(a);
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(visited[nq] > visited[q]+1){
                visited[nq] = visited[q]+1;
                cnt[nq] = cnt[q];
                que.push(nq);
            }else if(visited[nq] == visited[q]+1){
                cnt[nq] = (cnt[nq]+cnt[q])%MOD;
            }
        }
    }
}


int main(){
    int n, a, b, m; cin >> n >> a >> b >> m;
    rep(i, 0, m){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(a);
    cout << cnt[b] << endl;
}