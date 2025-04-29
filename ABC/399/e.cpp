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
constexpr ll INF = 1e18;

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
        maxi[rx] = std::max(maxi[rx],maxi[ry]);
        mini[rx] = std::min(mini[rx],mini[ry]);
    }

    inline ll min(ll x){
        return mini[root(x)];
    }

    inline ll max(int x){
        return maxi[root(x)];
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
    string s, t; cin >> s >> t;
    if(s == t){
        cout << 0 << endl;
        return 0;
    }
    
    int sigma = 26;
    vector<vector<int>> g(sigma);
    vector<vector<int>> rev(sigma);
    UnionFind uf(sigma);
    rep(i, 0, n){
        // if(s[i] == t[i]) continue;
        g[s[i]-'a'].push_back(t[i]-'a');
        uf.unite(s[i]-'a', t[i]-'a');
        rev[t[i]-'a'].push_back(s[i]-'a');
    }
    rep(i, 0, sigma){
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
        if(g[i].size() >= 2){
            cout << -1 << endl;
            return 0;
        }
        // if(!g[i].empty() && g[i][0] == i) g[i].pop_back();

        sort(rev[i].begin(), rev[i].end());
        rev[i].erase(unique(rev[i].begin(), rev[i].end()), rev[i].end());
    }

    // 全部サイクルを含んでいるとだめ
    bool ok = false;
    int cnt_cycle = 0;
    int ans = 0;
    rep(i, 0, sigma){
        if(uf[i] != i) continue;
        // 入次数 0 の頂点があるかどうか
        bool is_not_cycle = false;
        int start = -1;
        rep(u, 0, sigma){
            if(uf[u] != i) continue;
            if(rev[u].size() == 0) is_not_cycle = true, start = u; 
        }
        ok |= is_not_cycle;
        // if(is_not_cycle) cout << "Not cycle" << ' ' << i << endl;
        // else cout << "Cycle" << endl;
        if(!is_not_cycle){
            cnt_cycle++;
            if(uf.size(i) == 1) continue;
            ans += uf.size(i)+1;
        }else{
            bool is_include_cycle = false;
            queue<int> que;
            que.push(start);
            vector<bool> seen(sigma);
            seen[start] = true;
            while(!que.empty()){
                int q = que.front(); que.pop();
                for(auto nq: g[q]){
                    if(nq == q) continue;
                    if(seen[nq]){
                        is_include_cycle = true;
                        continue;
                    }
                    seen[nq] = true;
                    que.push(nq);
                }
            }
            if(is_include_cycle) ans += uf.size(i);
            else ans += uf.size(i)-1;
        }
    }
    if(!ok){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

  

    return 0;
}