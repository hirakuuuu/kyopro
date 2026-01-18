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
    int n, q; cin >> n >> q;
    vector<pair<int, int>> pos(n);
    auto d = [&](int i, int j) -> int {
        return abs(pos[i].first-pos[j].first)+abs(pos[i].second-pos[j].second);
    };
    vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> dist(n+q); 
    rep(i, 0, n){
        cin >> pos[i].first >> pos[i].second;
    }
    rep(i, 0, n){
        rep(j, 0, n){
            dist[i].push({d(i, j), j});
        }
    }

    UnionFind uf(n+q);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int a, b; cin >> a >> b;
            pos.push_back({a, b});
            rep(i, 0, n){
                dist[i].push({d(i, n), n});
                dist[n].push({d(i, n), i});
            }
            n++;
        }else if(t == 2){
            int mi = 2*IINF;
            rep(i, 0, n){
                while(!dist[i].empty() && uf.same(i, dist[i].top().second)){
                    dist[i].pop();
                }
                if(!dist[i].empty()){
                    chmin(mi, dist[i].top().first);
                }
            }
            if(mi == 2*IINF){
                cout << -1 << endl;
            }else{
                rep(i, 0, n){
                    while(!dist[i].empty() && dist[i].top().first == mi){
                        uf.unite(i, dist[i].top().second);
                        dist[i].pop();
                    }
                }
                cout << mi << endl;
            }
        }else{
            int u, v; cin >> u >> v;
            u--, v--;
            if(uf.same(u, v)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}