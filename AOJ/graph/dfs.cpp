#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

vector<vector<int>> g(105);
vector<int> d(105), f(105);

int cnt = 1;
void dfs(int pos){
    d[pos] = cnt;
    cnt++;
    for(auto npos: g[pos]){
        if(d[npos] == 0) dfs(npos);
    }
    f[pos] = cnt;
    cnt++;
}

int main(){
    int n; cin >> n;
    rep(i, 0, n){
        int j, k; cin >> j >> k;
        rep(l, 0, k){
            int v; cin >> v;
            g[j-1].push_back(v-1);
        }
        sort(g[j-1].begin(), g[j-1].end());
    }
    // グラフが連結とは限らないので、全ての頂点を訪問するようにループを書く必要がある
    rep(i, 0, n){
        if(d[i] == 0) dfs(i);
        printf("%d %d %d\n", i+1, d[i], f[i]);
    }
}