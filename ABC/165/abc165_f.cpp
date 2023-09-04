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
// https://atcoder.jp/contests/abc165/tasks/abc165_f

vector<ll> a(200005);
vector<vector<int>> g(200005);

vector<int> ans(200005);
vector<ll> lis(200005, INF);
void dfs(int pos, int par){
    int cnt = lower_bound(lis.begin(), lis.end(), a[pos])-lis.begin();
    ll tmp = lis[cnt];
    lis[cnt] = a[pos];
    ans[pos] = lower_bound(lis.begin(), lis.end(), INF)-lis.begin();
    for(auto npos: g[pos]){
        if(npos == par) continue;
        dfs(npos, pos);
    }
    lis[cnt] = tmp;
}

int main(){
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    rep(i, 0, n){
        cout << ans[i] << '\n';
    }
    
    
    return 0;
}