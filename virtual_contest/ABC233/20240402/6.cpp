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

class UnionFind {
    vector<ll> parent, maxi, mini;
    inline ll root(ll n){
        return (parent[n] < 0? n:parent[n] = root(parent[n]));
    }
public:
    UnionFind(ll n_ = 1): parent(n_, -1), maxi(n_), mini(n_){
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }

    inline bool same(ll x, ll y){
        return root(x) == root(y);
    }

    inline void unite(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return;
        if(parent[rx] > parent[ry]) swap(rx, ry);
        parent[rx] += parent[ry];
        parent[ry] = rx;
        maxi[x] = std::max(maxi[x],maxi[y]);
        mini[x] = std::min(mini[x],mini[y]);
    }

    inline ll min(ll x){
        return mini[root(x)];
    }

    inline ll max(int x){
        return mini[root(x)];
    }

    inline ll size(ll x){
        return (-parent[root(x)]);
    }

    inline ll operator[](ll x){
        return root(x);
    }

    inline void print(){
        rep(i, 0, (ll)parent.size()) cout << root(i) << " ";
        cout << endl;
    }

    void clear(){
        rep(i, 0, (ll)parent.size()){
            parent[i] = -1;
        }
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }
};

int main(){
    int n; cin >> n;
    vector<int> p(n), rev(n);
    rep(i, 0, n){
        cin >> p[i];
        p[i]--;
        rev[p[i]] = i;
    }
    int m; cin >> m;
    vector<pair<int, int>> ope(m);
    map<pair<int, int>, int> id;
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        ope[i] = {a, b};
        id[{a, b}] = id[{b, a}] = i;
    }
    UnionFind uf(n);
    vector<vector<int>> g(n);
    rep(i, 0, m){
        auto [a, b] = ope[i];
        if(uf.same(a, b)) continue;
        uf.unite(a, b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<set<int>> r(n);
    rep(i, 0, n){
        r[uf[i]].insert(i);
        r[uf[i]].insert(p[i]);
    }
    rep(i, 0, n){
        if(uf.size(i) != r[uf[i]].size()){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<int> seen(n);
    vector<pair<int, int>> ans;
    rep(i, 0, n){
        if(seen[i]) continue;
        vector<int> postorder;
        auto dfs1 = [&](auto self, int pos, int pre) -> void{
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                self(self, nxt, pos);
            }
            postorder.push_back(pos);
            seen[pos] = true;
        };
        dfs1(dfs1, i, -1);
        for(auto now: postorder){
            int start = rev[now];
            vector<pair<int, int>> path;
            auto dfs2 = [&](auto self, int pos, int pre) -> void{
                if(pos == now){
                    for(auto o: path){
                        ans.push_back(o);
                        swap(p[o.first], p[o.second]);
                        swap(rev[p[o.first]], rev[p[o.second]]);
                    }
                }
                for(auto nxt: g[pos]){
                    if(nxt == pre) continue;
                    path.push_back({pos, nxt});
                    self(self, nxt, pos);
                    path.pop_back();
                }
            };
            dfs2(dfs2, start, -1);
        }
    }
    cout << ans.size() << endl;
    for(auto aa: ans){
        cout << id[aa]+1 << ' ';
    }
    cout << endl;

    return 0;
}