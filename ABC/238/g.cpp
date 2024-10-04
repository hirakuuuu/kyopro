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
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 0ならば素数, 0でないなら最小の素因数
const int MAX_N = 2000005;
vector<int> erat(MAX_N+1);
void init_e(){
    rep(i, 2LL, (ll)sqrt(MAX_N)+1){
        if(erat[i] == 0){
            for(ll j = i*i; j <= MAX_N; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}

// 素因数分解 O(log{x})
vector<pair<int, int>> prime_factorization(ll x){
    vector<pair<int, int>> res;
    while(erat[x] != 0){
        ll p = erat[x];
        res.push_back({p, 0});
        while(x%p == 0){
            x /= p;
            res.back().second = (res.back().second+1)%3;
        }
        if(res.back().second == 0) res.pop_back();
    }
    if(x != 1) res.push_back({x, 1});
    return res;
};

class UnionFind {
    vector<ll> parent;
    inline ll root(ll n){
        return (parent[n] < 0? n:parent[n] = root(parent[n]));
    }
public:
    UnionFind(ll n_ = 1): parent(n_, -1){}

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
    }

    inline ll size(ll x){
        return (-parent[root(x)]);
    }

    inline ll operator[](ll x){
        return root(x);
    }
};


int main(){
    random_device seed_gen;
    mt19937 engine(seed_gen());
    
    init_e();
    int n, q; cin >> n >> q;
    vector<int> a(n);
    vector<vector<pair<int, int>>> pf(n);
    rep(i, 0, n){
        cin >> a[i];
        pf[i] = prime_factorization(a[i]);
    }
    vector<ll> h(1000005);
    unordered_map<ll, bool> used;
    rep(i, 2, 1000005){
        if(erat[i] == 0){
            ll tmp = engine();
            while(used[tmp]) tmp = engine();
            h[i] = tmp;
            used[tmp] = true;
        }
    }

    vector<int> r(n, -1);
    map<ll, int> l;
    l[0] = -1;
    ll tmp = 0;
    vector<int> cnt(1000005);
    rep(cr, 0, n){
        for(auto [p, e]: pf[cr]){
            if((cnt[p]+e)%3 == 0){
                tmp -= h[p]*cnt[p];
                tmp %= MOD;
                if(tmp < 0) tmp += MOD;
                cnt[p] = 0;
            }else{
                if(cnt[p]+e == 4){
                    tmp -= h[p]; tmp %= MOD;
                    if(tmp < 0) tmp += MOD;
                }else{
                    tmp += h[p]*e; tmp %= MOD;
                }
                cnt[p] = (cnt[p]+e)%3;
            }
        }
        if(l.find(tmp) != l.end()){
            r[l[tmp]+1] = cr;
        }
        l[tmp] = cr;
    }
    UnionFind uf(n+1);
    rep(i, 0, n){
        if(r[i] == -1) continue;
        uf.unite(i, r[i]+1);
    }


    while(q--){
        int L, R; cin >> L >> R;
        L--;
        if(uf.same(L, R)) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
    
    return 0;
}