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
// https://atcoder.jp/contests/abc328/tasks/abc328_e

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
    int n, m;
    ll k; cin >> n >> m >> k;
    vector<ll> u(m), v(m), w(m);
    rep(i, 0, m){
        cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;
    }

    ll ans = k;
    queue<ll> que;
    que.push(0);
    map<ll, bool> seen;
    while(!que.empty()){
        ll q = que.front(); que.pop();
        UnionFind uf(n);
        int cnt = 0;
        ll cost = 0;
        rep(i, 0, m){
            if((q>>i)&1){
                uf.unite(u[i], v[i]);
                cnt++;
                cost += w[i];
            }
        }

        if(cnt == n-1){
            chmin(ans, cost%k);
        }else{
            rep(i, 0, m){
                if(!((q>>i)&1)){
                    if(!uf.same(u[i], v[i]) && !seen[q+(1LL<<i)]){
                        seen[q+(1LL<<i)] = true;
                        que.push(q+(1LL<<i));
                    }
                }
            }
        }

    }
    cout << ans << endl;
    
    return 0;
}