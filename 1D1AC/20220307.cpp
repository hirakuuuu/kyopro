#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

vector<int> a(200005), b(200005), parent(200005, -1);
vector<ll> val(200005), ans(200005);
vector<vector<int>> g(200005);

void dfs1(int pos, int pre){
    for(auto npos: g[pos]){
        if(npos == pre) continue;
        parent[npos] = pos;
        dfs1(npos, pos);
    }
}

void dfs2(int pos, int pre, ll cnt){
    ans[pos] = val[pos]+cnt;
    for(auto npos: g[pos]){
        if(npos == pre) continue;
        dfs2(npos, pos, ans[pos]);
    }
}

int main(){
    int n; cin >> n;
    rep(i, 1, n){
        cin >> a[i] >> b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    dfs1(1, 0);
    int q; cin >> q;
    ll total = 0;
    while(q--){
        ll t, e, x; cin >> t >> e >> x;
        if(t == 1){
            if(parent[a[e]] == b[e]) val[a[e]] += x;
            else{
                total += x;
                val[b[e]] -= x;
            }
        }else{
            if(parent[a[e]] == b[e]){
                total += x;
                val[a[e]] -= x;
            }else val[b[e]] += x;
        }
    }
    dfs2(1, 0, total);
    rep(i, 1, n+1){
        cout << ans[i] << endl;
    }
}