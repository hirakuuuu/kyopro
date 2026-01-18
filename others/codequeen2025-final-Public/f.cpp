#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


const int vmax = 1000005; // ここは問題ごとに考慮が必要
mint fact[vmax], finv[vmax];
void initfact(){
	fact[0]= 1;
	for(int i = 1; i < vmax; i++) fact[i] = fact[i-1]*i; // 階乗の計算
	finv[vmax-1] = fact[vmax-1].inv();
	for(int i = vmax-2; i >=0; i--) finv[i] = finv[i+1]*(i+1); // 階乗の逆元
}
// nCk
mint choose(int n,int k){
    if(n < 0 || k < 0 || n < k) return 0;
    if(n == 0 && k == 0) return 1;
	return fact[n]*finv[n-k]*finv[k];
}
// (a+b)!/(a!b!)
mint binom(int a,int b){
	return 0<=a&&0<=b?fact[a+b]*finv[a]*finv[b]:0;
}
// カタラン数（括弧列とか）
mint catalan(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}
// 重複組み合わせ
mint homogeneous(int n, int k){
    return choose(n+k-1, k);
}

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
    initfact();

    int n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, 0, m){
        cin >> a[i] >> b[i]; a[i]--, b[i]--;
    }

    vector<int> nodes;
    rep(i, 0, m){
        nodes.push_back(a[i]);
        nodes.push_back(b[i]);
    }
    sort(nodes.begin(), nodes.end());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
    int nv = nodes.size();

    map<int, int> id;
    rep(i, 0, nv) id[nodes[i]] = i;

    vector<mint> dp(1<<m, 1);
    rep(i, 0, 1<<m){
        vector<int> deg(nv);
        UnionFind uf(nv);
        bool ok = true;
        rep(j, 0, m){
            if((i>>j)&1){
                deg[id[a[j]]]++;
                deg[id[b[j]]]++;
                if(uf.same(id[a[j]], id[b[j]])) ok = false;
                uf.unite(id[a[j]], id[b[j]]);
            }
        }

        rep(j, 0, nv){
            if(deg[j] >= 3) ok = false;
        }
        if(!ok) dp[i] = 0;

        int cnt = 0, cc = 0;
        rep(j, 0, nv){
            if(uf[j] != j) continue;
            if(uf.size(j) == 1) continue;
            cnt += uf.size(j);
            cc++;
            dp[i] *= 2;
        }
        dp[i] *= fact[n-cnt+cc];
    }

    mint elm = 0;
    rep(i, 1, 1<<m){
        // cout << i << ' ' << dp[i].val() << endl;
        if(__popcount(i)%2 == 1) elm += dp[i];
        else elm -= dp[i];
    }
    cout << (fact[n]-elm).val() << endl;
    
    return 0;
}