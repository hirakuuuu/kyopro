#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, q; cin >> n >> q;
    vector<vector<int>> g(n);
    rep(i, 1, n){
        int p; cin >> p;
        p--;
        g[p].push_back(i);
    }
    int time = 0;
    vector<int> preorder(n), postorder(n);
    auto dfs = [&](auto self, int pos) -> void {
        preorder[pos] = time++;
        for(auto nxt: g[pos]){
            self(self, nxt);
        }
        postorder[pos] = time++;
    };
    dfs(dfs, 0);

    vector<pair<int, int>> r(n);
    rep(i, 0, n) r[i] = {preorder[i], i};
    sort(r.begin(), r.end());
    while(q--){
        int u, k; cin >> u >> k;
        u--, k--;
        int pos = lower_bound(r.begin(), r.end(), make_pair(preorder[u], u))-r.begin();
        if(pos+k < n){
            int x = r[pos+k].second;
            if(postorder[x] <= postorder[u]){
                cout << x+1 << endl;
            }else{
                cout << -1 << endl;
            }
        }else{
            cout << -1 << endl;
        }

    }


    return 0;
}