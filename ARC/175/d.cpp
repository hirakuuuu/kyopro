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

/*
部分木のサイズの分だけ増減する予想
LISは末尾に要素を追加したときに、長さが1増えるか変わらないかでしかない
よって、増える位置を決め打って、構築できるかを考えればよい
実は、部分木のサイズについての部分和問題は降順に使えるなら使うと考えて問題ない
*/

int main(){
    int n; cin >> n;
    ll k; cin >> k;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // kが達成可能かどうか
    vector<ll> sz(n, 1), depth(n);
    auto dfs = [&](auto self, int pos, int pre) -> void {
        if(pre != -1) depth[pos] = depth[pre]+1;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
            sz[pos] += sz[nxt];
        }
    };
    dfs(dfs, 0, -1);
    ll sum = 0;
    rep(i, 0, n) sum += depth[i];
    if(k < n || sum+n < k){
        cout << "No" << endl;
        return 0;
    }

    // 部分和問題が解を持つかどうか
    vector<pair<ll, ll>> w(n);
    vector<int> s(n);
    ll rest = k-n;
    rep(i, 0, n) w[i] = {sz[i], i};
    sort(w.rbegin(), w.rend());
    rep(i, 1, n){
        auto [t, id] = w[i];
        if(rest >= t){
            rest -= t;
            s[id] = 1;
        }
    }
    if(rest != 0){
        cout << "No" << endl;
        return 0;
    }

    // Pを構築
    vector<pair<int, int>> q(n);
    rep(i, 0, n){
        if(s[i]) q[i] = {depth[i], i};
        else q[i] = {-depth[i], i};
    }
    sort(q.begin(), q.end());
    vector<int> p(n);
    rep(i, 0, n){
        auto [d, id] = q[i];
        p[id] = i;
    }
    cout << "Yes" << endl;
    rep(i, 0, n){
        cout << p[i]+1 << ' ';
    }
    cout << endl;

    


    
    return 0;
}