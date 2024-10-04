#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<vector<pair<ll, ll>>> g(n);
    ll sum = 0;
    rep(i, 0, n-1){
        ll u, v, l; cin >> u >> v >> l;
        u--, v--;
        g[u].push_back({v, l});
        g[v].push_back({u, l});
        sum += l;
    }

    vector<multiset<ll>> score(n); 
    auto dfs = [&](auto self, int pos, int pre) -> void {
        if(pos != 0 && g[pos].size() == 1){
            score[pos].insert(0LL);
            return;
        }
        for(auto [nxt, w]: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
            auto itr = score[nxt].rbegin();
            ll tmp = *itr;
            score[nxt].erase(score[nxt].find(tmp));
            score[nxt].insert(tmp+2*w);
            if(score[pos].size() < score[nxt].size()) swap(score[pos], score[nxt]);
            for(auto ss: score[nxt]) score[pos].insert(ss);
            score[nxt].clear();
        }
    };
    dfs(dfs, 0, -1);
    vector<ll> ans(n);
    int id = 0;
    for(auto ss: score[0]){
        ans[score[0].size()-id-1] = ss;
        id++;
    }
    rep(i, 0, n-1){
        ans[i+1] += ans[i];
    }
    rep(i, 0, n){
        cout << ans[i] << endl;
    }

    
    return 0;
}