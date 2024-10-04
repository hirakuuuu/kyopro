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

class UnionFind {
    vector<ll> parent;
    inline ll root(ll n){
        return (parent[n] < 0? n:parent[n] = root(parent[n]));
    }
public:
    UnionFind(ll n_ = 1): parent(n_, -1){}

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
    }

    inline ll size(ll x){
        return (-parent[root(x)]);
    }

    inline ll operator[](ll x){
        return root(x);
    }
};

int main(){
    int n;
    ll k; cin >> n >> k;
    vector<int> x(n), a(n);
    UnionFind uf(n);
    vector<vector<int>> c(n);
    vector<int> id(n, -1), cid(n, -1);
    vector<int> indegree(n);
    rep(i, 0, n){
        cin >> x[i];
        x[i]--;
        indegree[x[i]]++;
        if(!uf.same(i, x[i])){
            uf.unite(i, x[i]);
        }else{
            // 閉路
            c[i].push_back(i);
            id[i] = 0;
            cid[i] = i;
            int pos = x[i];
            while(pos != i){
                id[pos] = c[i].size();
                cid[pos] = i;
                c[i].push_back(pos);
                pos = x[pos];
            }
        }
    }
    rep(i, 0, n) cin >> a[i];

    vector<int> to(n, -1), dist(n);
    auto dfs = [&](auto self, int pos) -> void {
        if(id[x[pos]] != -1){
            to[pos] = x[pos];
            dist[pos] = 1;
            return;
        }

        self(self, x[pos]);
        to[pos] = to[x[pos]];
        dist[pos] = dist[x[pos]]+1;
        return;
    };
    rep(i, 0, n){
        if(indegree[i]) continue;
        dfs(dfs, i);
    }

    rep(i, 0, n){
        int nxt = to[i], d = dist[i];
        ll tmp = k-d;
        cout << c[cid[nxt]].size() << endl;
        tmp %= c[cid[nxt]].size();
        int goal = c[cid[nxt]][(id[nxt]+tmp)%c[cid[nxt]].size()];
        cout << a[goal] << ' ';
    }
    cout << endl;

    
    return 0;
}