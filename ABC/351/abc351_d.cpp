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
    int h, w; cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    vector<vector<char>> t(h, vector<char>(w));
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> s[i][j];
            t[i][j] = s[i][j];
        }
    }
    rep(i, 0, h){
        rep(j, 0, w){
            bool ok = true;
            rep(k, 0, 4){
                int ni = i+(k-1)%2, nj = j+(k-2)%2;
                if(inr(0, ni, h) && inr(0, nj, w)){
                    if(s[ni][nj] == '#') ok = false;
                }
            }
            if(!ok) t[i][j] = '#';
        }
    }
    auto id =[&](int i, int j) -> int{
        return i*w+j;
    };
    UnionFind uf(h*w);
    rep(i, 0, h){
        rep(j, 0, w){
            if(t[i][j] == '#') continue;
            rep(k, 0, 4){
                int ni = i+(k-1)%2, nj = j+(k-2)%2;
                if(inr(0, ni, h) && inr(0, nj, w)){
                    if(t[ni][nj] != '#') uf.unite(id(i, j), id(ni, nj));                    
                }
            }
        }
    }
    int ans = 1;
    map<int, bool> seen;
    vector<vector<int>> d(h, vector<int>(w, -1));

    rep(i, 0, h){
        rep(j, 0, w){
            if(t[i][j] == '#') continue;
            if(seen[uf[id(i, j)]]) continue;
            seen[uf[id(i, j)]] = true;
            set<int> tmp;
            queue<pair<int, int>> que;
            que.push({i, j});
            d[i][j] = 0;
            while(!que.empty()){
                auto [ci, cj] = que.front(); que.pop();
                rep(k, 0, 4){
                    int ni = ci+(k-1)%2, nj = cj+(k-2)%2;
                    if(inr(0, ni, h) && inr(0, nj, w)){
                        if(t[ni][nj] == '#'){
                            if(s[ni][nj] == '.') tmp.insert(id(ni, nj));
                        }else{
                            if(d[ni][nj] != -1) continue;
                            d[ni][nj] = 0;
                            que.push({ni, nj});
                        }
                    }
                }
            }
            chmax(ans, uf.size(id(i, j))+tmp.size());
        }
    }
    cout << ans << endl;
    
    return 0;
}