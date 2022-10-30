#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


vector<vector<pii>> g(100005);
vector<int> parent(10005, -1);
int root(int x){
    if(parent[x] < 0) return x;
    return parent[x] = root(parent[x]);
}

bool same(int x, int y){
    return root(x) == root(y);
}

void unite(int x, int y){
    x = root(x);
    y = root(y);
    if(parent[x] > parent[y]) swap(x, y);
    parent[x] += parent[y];
    parent[y] = x;
}

int main(){
    int v, e; cin >> v >> e;
    priority_queue<vector<int> , vector<vector<int>>, greater<vector<int>>> que;
    rep(i, 0, e){
        int s, t, w; cin >> s >> t >> w;
        que.push({w, s, t});
    }
    ll sum_w = 0;
    while(!que.empty()){
        vector<int> q = que.top(); que.pop();
        if(same(q[1], q[2])) continue;
        unite(q[1], q[2]);
        sum_w += q[0];
    }
    cout << sum_w << endl;
}