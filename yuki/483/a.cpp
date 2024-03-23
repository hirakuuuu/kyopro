#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define inr(l, x, r) (l <= x && x < r)
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
    int h, w, n, d; cin >> h >> w >> n >> d;
    vector<int> x(n), y(n);
    vector<vector<bool>> star(h, vector<bool>(w));
    rep(i, 0, n){
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
        star[x[i]][y[i]] = true;
    }
    vector<pair<int, int>> dif;
    rep(i, -d, d+1){
        rep(j, -d, d+1){
            if(abs(i)+abs(j) <= d) dif.push_back({i, j});
        }
    }
    UnionFind uf(h*w);
    auto id = [&](int i, int j)->int {
        return i*w+j;
    };
    rep(i, 0, n){
        for(auto [di, dj]: dif){
            if(inr(0, x[i]+di, h) && inr(0, y[i]+dj, w) && star[x[i]+di][y[i]+dj]){
                uf.unite(id(x[i], y[i]), id(x[i]+di, y[i]+dj));
            }
        }
    }

    set<int> r;
    rep(i, 0, n) if(uf.size(id(x[i], y[i])) >= 2){
        r.insert(uf[id(x[i], y[i])]);
    }
    int mi = r.size(), mx = 0;
    rep(i, 0, h){
        rep(j, 0, w){
            if(star[i][j]) continue;
            set<int> seiza;
            int cnt_star = 0;
            for(auto [di, dj]: dif){
                if(inr(0, i+di, h) && inr(0, j+dj, w) && star[i+di][j+dj]){
                    if(uf.size(id(i+di, j+dj)) >= 2) seiza.insert(uf[id(i+di, j+dj)]);
                    else cnt_star++;
                }
            }
            if(!seiza.empty()) chmin(mi, r.size()-seiza.size()+1);
            else if(cnt_star) chmin(mi, r.size()+1);
            else chmin(mi, r.size());

            if(!seiza.empty()) chmax(mx, r.size()-seiza.size()+1);
            else if(cnt_star) chmax(mx, r.size()+1);
            else chmax(mx, r.size());
        }
    }
    cout << mi << ' ' << mx << endl;
    return 0;
}