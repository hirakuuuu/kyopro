#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

vector<vector<int>> g(100005);
vector<int> x(100005);
vector<vector<int>> p_tree(100005);

// 木DPは根から探索を始める
// 木DP
void dfs(int pos, int pre){
    p_tree[pos].push_back(x[pos]);
    for(auto ns: g[pos]){
        if(ns == pre) continue;
        dfs(ns, pos);
        for(auto nss: p_tree[ns]){
            if(p_tree[pos].size() < 20){
                p_tree[pos].push_back(nss);
                sort(p_tree[pos].begin(), p_tree[pos].end());
            }else{
                if(nss > p_tree[pos][0]){
                    p_tree[pos][0] = nss;
                    sort(p_tree[pos].begin(), p_tree[pos].end());
                }
            }
        }
    }
    reverse(p_tree[pos].begin(), p_tree[pos].end());
}

int main(){
    int n, q; cin >> n >> q;
    rep(i, 0, n) cin >> x[i];
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    dfs(0, -1);
    while(q--){
        int v, k; cin >> v >> k;
        cout << p_tree[v-1][k-1] << endl;
    } 
}