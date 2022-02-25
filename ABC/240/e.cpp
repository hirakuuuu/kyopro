#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

vector<vector<int>> g(200005);
int cnt = 1;
vector<pii> ans(200005, make_pair(-1, -1));
void dfs(int pos, int pre){
    if(g[pos].size() > 1 or g[pos][0] != pre){
        for(auto npos: g[pos]){
            if(npos == pre) continue;
            dfs(npos, pos);
            if(ans[pos] == make_pair(-1, -1)) ans[pos] = ans[npos];
            else{
                if(ans[pos].first > ans[npos].first) ans[pos] = make_pair(ans[npos].first, ans[pos].second);
                if(ans[pos].second < ans[npos].second) ans[pos] = make_pair(ans[pos].first, ans[npos].second);
            }
        }
    }else{
        ans[pos] = make_pair(cnt, cnt);
        cnt++;
    }
}

int main(){
    int n; cin >> n;
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }
    dfs(0, -1);
    rep(i, 0, n){
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}