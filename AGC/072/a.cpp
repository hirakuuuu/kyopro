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
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        ll d; cin >> d;
        vector<ll> t(n), x(n);
        rep(i, 0, n){
            cin >> t[i] >> x[i];
        }

        // 必要条件の判定
        UnionFind uf(n);
        rep(i, 0, n){
            rep(j, i+1, n){
                if(t[i]+x[i]+x[j] > t[j]+d && t[j]+x[i]+x[j] > t[i]+d) continue;
                uf.unite(i, j);
            }
        }
        if(uf.size(0) < n){
            cout << "No" << endl;
            continue;
        }

        {
            vector<vector<int>> g(n);
            vector<int> indeg(n);
            rep(i, 0, n){
                rep(j, i+1, n){
                    if(t[i]+x[i]+x[j] <= t[j]+d && t[j]+x[i]+x[j] <= t[i]+d) continue;
                    
                    if(t[i]+x[i]+x[j] <= t[j]+d) g[i].push_back(j), indeg[j]++;
                    if(t[j]+x[i]+x[j] <= t[i]+d) g[j].push_back(i), indeg[i]++;
    
                }
            }
    
            vector<int> p;
            priority_queue<tuple<ll, ll, int>, vector<tuple<ll, ll, int>>, greater<tuple<ll, ll, int>>> que;
            rep(i, 0, n) if(indeg[i] == 0) que.push({t[i], x[i]+t[i], i});
            
            while(!que.empty()){
                auto [_, __, q] = que.top(); que.pop();
                p.push_back(q);
                for(auto nq: g[q]){
                    indeg[nq]--;
                    if(indeg[nq] == 0) que.push({t[nq], x[nq]+t[nq], nq});
                }
            }
    
            assert(p.size() == n);
            ll time = 0;
            bool ok = true;;
            rep(i, 0, n){
                // cout << p[i] << ' ' << time+x[p[i]] << ' ' << t[p[i]]+d << endl;
                if(time+x[p[i]] > t[p[i]]+d){
                    ok = false;
                    break;
                }
                time = max(time+x[p[i]], t[p[i]])+x[p[i]];
            }
            if(ok){
                cout << "Yes" << endl;
                continue;
            }
        }

        {
            vector<vector<int>> g(n);
            vector<int> indeg(n);
            rep(i, 0, n){
                rep(j, i+1, n){
                    if(t[i]+x[i]+x[j] <= t[j]+d && t[j]+x[i]+x[j] <= t[i]+d) continue;
                    
                    if(t[i]+x[i]+x[j] <= t[j]+d) g[i].push_back(j), indeg[j]++;
                    if(t[j]+x[i]+x[j] <= t[i]+d) g[j].push_back(i), indeg[i]++;
    
                }
            }
    
            vector<int> p;
            priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
            rep(i, 0, n) if(indeg[i] == 0) que.push({x[i]+t[i], i});
            
            while(!que.empty()){
                auto [_, q] = que.top(); que.pop();
                p.push_back(q);
                for(auto nq: g[q]){
                    indeg[nq]--;
                    if(indeg[nq] == 0) que.push({x[nq]+t[nq], nq});
                }
            }
    
            assert(p.size() == n);
            ll time = 0;
            bool ok = true;;
            rep(i, 0, n){
                // cout << p[i] << ' ' << time+x[p[i]] << ' ' << t[p[i]]+d << endl;
                if(time+x[p[i]] > t[p[i]]+d){
                    ok = false;
                    break;
                }
                time = max(time+x[p[i]], t[p[i]])+x[p[i]];
            }
            if(ok){
                cout << "Yes" << endl;
                continue;
            }
        }

        cout << "No" << endl;
    }
    
    return 0;
}