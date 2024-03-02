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
// 

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
    vector<string> s(h+2);
    rep(i, 0, w+2){
        s[0] += '.';
        s[h+1] += '.';
    }
    rep(i, 1, h+1){
        string t; cin >> t;
        s[i] = '.'+t+'.';
    }
    UnionFind uf(h*w);
    auto id = [&](int i, int j)->int {
        return (i-1)*w+(j-1);
    };
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, 1, -1, -1, 0, 1};
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            if(s[i][j] == '.') continue;
            rep(k, 0, 8){
                int nx = i+dx[k], ny = j+dy[k];
                if(s[nx][ny] == '#'){
                    uf.unite(id(i, j), id(nx, ny));
                }
            }
        }
    }
    set<int> ans;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            if(s[i][j] == '#') ans.insert(uf[id(i, j)]);
        }
    }
    cout << ans.size() << endl;


    return 0;
}