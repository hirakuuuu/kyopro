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
// https://atcoder.jp/contests/abc049/tasks/arc065_b

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
    int n, k, l; cin >> n >> k >> l;
    vector<int> p(k), q(k), s(l), r(l);
    rep(i, 0, k) cin >> p[i] >> q[i];
    rep(i, 0, l) cin >> s[i] >> r[i];

    UnionFind road(n+1), train(n+1);
    rep(i, 0, k) road.unite(p[i], q[i]);
    rep(i, 0, l) train.unite(s[i], r[i]);

    vector<vector<int>> road_component(n+1), train_component(n+1);

    rep(i, 1, n+1){
        road_component[road[i]].push_back(i);
        train_component[train[i]].push_back(i);
    }

    vector<int> ans(n+1);
    map<pii, int> memo;
    rep(i, 1, n+1){
        int rrep = road[i], trep = train[i];
        if(memo[{rrep, trep}] > 0){
            ans[i] = memo[{rrep, trep}];
        }else{
            if(road_component[rrep].size() < train_component[trep].size()){
                for(auto rc: road_component[rrep]){
                    if(rc == *lower_bound(train_component[trep].begin(), train_component[trep].end(), rc)){
                        ans[i]++;
                    }
                }
            }else{
                for(auto tc: train_component[trep]){
                    if(tc == *lower_bound(road_component[rrep].begin(), road_component[rrep].end(), tc)){
                        ans[i]++;
                    }
                }  
            }
            memo[{rrep, trep}] = ans[i];
        }
    }

    rep(i, 1, n+1) cout << ans[i] << ' ';
    cout << endl;



    
    
    return 0;
}