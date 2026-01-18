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
    int t; cin >> t;
    while(t--){
        int h, w; cin >> h >> w;
        vector<string> s(h);
        UnionFind uf(4*h*w);
        auto id = [&](int i, int j) -> int {
            return i*w+j;
        };
        // UDLR;
        rep(i, 0, h){
            cin >> s[i];
            rep(j, 0, w){
                if(i-1 >= 0) uf.unite(id(i, j)*4, id(i-1, j)*4+1);
                if(i+1 < h) uf.unite(id(i, j)*4+1, id(i+1, j)*4);
                if(j-1 >= 0) uf.unite(id(i, j)*4+2, id(i, j-1)*4+3);
                if(j+1 < w) uf.unite(id(i, j)*4+3, id(i, j+1)*4+2);
                
                if(s[i][j] == 'A'){
                    uf.unite(id(i, j)*4, id(i, j)*4+1);
                    uf.unite(id(i, j)*4+2, id(i, j)*4+3);
                }else if(s[i][j] == 'B'){
                    uf.unite(id(i, j)*4, id(i, j)*4+3);
                    uf.unite(id(i, j)*4+1, id(i, j)*4+2);
                }else{
                    uf.unite(id(i, j)*4, id(i, j)*4+2);
                    uf.unite(id(i, j)*4+1, id(i, j)*4+3);
                }
            }
        }

        map<int, int> ids;
        int idx = 0;
        rep(i, 0, 4*h*w){
            if(i == uf[i]){
                ids[i] = idx++;
            }
        }
        vector<vector<int>> g(idx);
        rep(i, 0, h){
            rep(j, 0, w){
                rep(k, 0, 4){
                    rep(l, k+1, 4){
                        if(uf[id(i, j)*4+k] != uf[id(i, j)*4+l]){
                            g[ids[uf[id(i, j)*4+k]]].push_back(ids[uf[id(i, j)*4+l]]);
                        }
                    }
                }
            }
        }
        rep(j, 0, idx){
            sort(g[j].begin(), g[j].end());
            g[j].erase(unique(g[j].begin(), g[j].end()), g[j].end());
        }

        queue<int> que;
        vector<int> seen(idx, -1);
        que.push(ids[uf[id(0, 0)*4+2]]);
        seen[ids[uf[id(0, 0)*4+2]]] = 0;
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto nq: g[q]){
                if(seen[nq] != -1) continue;
                seen[nq] = seen[q]+1;
                que.push(nq);
            }
        }
        cout << seen[ids[uf[id(h-1, w-1)*4+3]]] << endl;
    }
    
    return 0;
}