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
// https://atcoder.jp/contests/abc324/tasks/abc324_f

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
    ll n, m; cin >> n >> m;
    vector<tuple<double, ll, ll, ll, ll, ll>> edge(m);
    vector<ll> u(m), v(m), b(m), c(m);
    vector<vector<tuple<ll, ll, ll>>> g(n);
    rep(i, 0, m){
        cin >> u[i] >> v[i] >> b[i] >> c[i];
        u[i]--, v[i]--;
        g[v[i]].emplace_back(u[i], b[i], c[i]);
    }
    
    double l = 0.0, r = 1e9;
    queue<ll> que;
    while(r-l > 10e-10){
        double mid = (r+l)/2.0;

        vector<double> dp(n, -9e18);
        dp[0] = 0.0;
        rep(i, 0, n){
            for(auto e: g[i]){
                auto [uu, bb, cc] = e;
                chmax(dp[i], dp[uu]+(double)bb-(double)cc*mid); 
            }
        }

        if(dp[n-1] > 0.0) l = mid;
        else r = mid;
    }

    printf("%.10f\n", l);
    
    return 0;
}