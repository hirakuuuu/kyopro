#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

struct Pos{
    ll x, y;
};

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

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n, x, y; cin >> n >> x >> y;
    

    vector<pair<Pos, Pos>> rect = {{Pos(0, 0), Pos(x, y)}};
    rep(_, 0, n){
        char c; cin >> c;
        ll a, b; cin >> a >> b;
        vector<pair<Pos, Pos>> nrect;
        if(c == 'X'){
            for(auto [p, q]: rect){
                if(q.x <= a){
                    p.y -= b;
                    q.y -= b;
                    nrect.push_back({p, q});
                }else if(a <= p.x){
                    p.y += b;
                    q.y += b;
                    nrect.push_back({p, q});
                }else{
                    auto p1 = p, q1 = q;
                    q1.x = a;
                    p1.y -= b;
                    q1.y -= b;

                    auto p2 = p, q2 = q;
                    p2.x = a;
                    p2.y += b;
                    q2.y += b;
                    nrect.push_back({p1, q1});
                    nrect.push_back({p2, q2});
                }
            }
        }else{
            for(auto [p, q]: rect){
                if(q.y <= a){
                    p.x -= b;
                    q.x -= b;
                    nrect.push_back({p, q});
                }else if(a <= p.y){
                    p.x += b;
                    q.x += b;
                    nrect.push_back({p, q});
                }else{
                    auto p1 = p, q1 = q;
                    q1.y = a;
                    p1.x -= b;
                    q1.x -= b;
                    auto p2 = p, q2 = q;
                    p2.y = a;
                    p2.x += b;
                    q2.x += b;
                    nrect.push_back({p1, q1});
                    nrect.push_back({p2, q2});
                }
            }
        }
        swap(rect, nrect);
    }

    int m = (int)rect.size();
    UnionFind uf(m);
    rep(i, 0, m){
        // cout << rect[i].first.x << ' ' << rect[i].first.y << ' ' << rect[i].second.x << ' ' << rect[i].first.y << endl;
        rep(j, 0, m){
            if(i == j) continue;
            if(rect[i].second.x == rect[j].first.x){
                if(!(rect[i].second.y <= rect[j].first.y || rect[j].second.y <= rect[i].first.y)) uf.unite(i, j);
            }
            if(rect[j].second.x == rect[i].first.x){
                if(!(rect[i].second.y <= rect[j].first.y || rect[j].second.y <= rect[i].first.y)) uf.unite(i, j);
            }
            if(rect[i].second.y == rect[j].first.y){
                if(!(rect[i].second.x <= rect[j].first.x || rect[j].second.x <= rect[i].first.x)) uf.unite(i, j);
            }
            if(rect[j].second.y == rect[i].first.y){
                if(!(rect[i].second.x <= rect[j].first.x || rect[j].second.x <= rect[i].first.x)) uf.unite(i, j);
            }
        }
    }

    vector<ll> sum(m);
    rep(i, 0, m){
        ll sz = (rect[i].second.x-rect[i].first.x)*(rect[i].second.y-rect[i].first.y);
        sum[uf[i]] += sz;
    }
    sort(sum.begin(), sum.end());
    int l = 0;
    while(sum[l] == 0) l++;
    cout << m-l << endl;
    rep(i, l, m) cout << sum[i] << ' ';
    cout << endl;

    return 0;
}