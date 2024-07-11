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
// https://atcoder.jp/contests/abc345/tasks/abc345_f

int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    if(k%2){
        cout << "No" << endl;
        return 0;
    }

    int total = 0;
    vector<int> cnt(n), seen(n);
    vector<int> ans;
    auto dfs = [&](auto self, int pos, int pre) -> void {
        if(seen[pos]) return;
        seen[pos] = true;
        for(auto [nxt, id]: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
            if(cnt[nxt] == 0 && total < k){
                total -= cnt[nxt]+cnt[pos];
                cnt[pos] ^= 1;
                cnt[nxt] ^= 1;
                total += cnt[nxt]+cnt[pos];
                ans.push_back(id);
            }
        }
    };
    rep(i, 0, n){
        dfs(dfs, i, -1);
    }
    
    if(total == k){
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        for(auto aa: ans) cout << aa+1 << ' ';
        cout << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}