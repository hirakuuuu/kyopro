#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

vector<vector<int>> g(10005);
vector<int> enter(10005);
vector<int> ans;
void topo(int v){
    rep(i, 0, v){
        if(enter[i] == 0){
            queue<int> que;
            que.push(i);
            while (!que.empty()){
                int q = que.front(); que.pop();
                ans.push_back(q);
                for(auto nq: g[q]){
                    enter[nq]--;
                    if(enter[nq] == 0){
                        que.push(nq);
                        enter[nq]--;
                    }
                }
            }
        }
    }
}


int main(){
    int v, e; cin >> v >> e;
    rep(i, 0, e){
        int s, t; cin >> s >> t;
        g[s].push_back(t);
        enter[t]++;
    }
    topo(v);
    for(auto aa: ans){
        cout << aa << endl;
    }
}