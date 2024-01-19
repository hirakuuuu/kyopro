#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/tdpc/tasks/tdpc_tree

template <ll MOD> class modint {
    ll val;
    static vector<modint<MOD>> factorial_vec;
public:
    // コンストラクタ
    modint(ll x = 0){
        val = x % MOD;
        if(val < 0) x += MOD;
    }

    // 入出力ストリーム
    friend constexpr istream &operator>>(istream &is, modint<MOD> &x){
        ll y; is >> y;
        x = y;
        return is;
    }
    friend constexpr ostream &operator<<(ostream &os, const modint<MOD> &x){
        return os << x.val;
    }

    // 算術演算子
    modint<MOD> operator -(){return modint<MOD>(-val);}
    modint<MOD> operator +(const modint<MOD> &r) const { return modint<MOD>(*this) += r; }
    modint<MOD> operator -(const modint<MOD> &r) const { return modint<MOD>(*this) -= r; }
    modint<MOD> operator *(const modint<MOD> &r) const { return modint<MOD>(*this) *= r; }
    modint<MOD> operator /(const modint<MOD> &r) const { return modint<MOD>(*this) /= r; }

    // 代入演算子
    modint<MOD> &operator +=(const modint<MOD> &r){
        val += r.val;
        if(val >= MOD) val -= MOD;
        return *this;
    }
    modint<MOD> &operator -=(const modint<MOD> &r){
        if(val < r.val) val += MOD;
        val -= r.val;
        return *this;
    }
    modint<MOD> &operator *=(const modint<MOD> &r){
        val = val*r.val%MOD;
        if(val < 0) val += MOD;
        return *this;
    }
    modint<MOD> &operator /=(const modint<MOD> &r){
        *this *= inv(r);
        return *this;
    }

    //等価比較演算子
    bool operator ==(const modint<MOD>& r){return this -> val == r.val;}
    bool operator !=(const modint<MOD>& r){return this -> val != r.val;}
    bool operator <(const modint<MOD>& r){return this -> val < r.val;}
    bool operator <=(const modint<MOD>& r){return this -> val <= r.val;}
    bool operator >(const modint<MOD>& r){return this -> val > r.val;}
    bool operator >=(const modint<MOD>& r){return this -> val >= r.val;}

    // 累乗
    static modint<MOD> modpow(modint<MOD> num, ll exp){
        if(!exp) return modint<MOD>(1); // 0乗
        modint<MOD> ret(1);
        modint<MOD> tmp = num;
        while(exp){
            if(exp&1) ret *= tmp;
            tmp *= tmp;
            exp >>= 1;
        }
        return ret;
    }

    // 逆元
    static modint<MOD> inv(modint<MOD> num){
        return modpow(num, MOD-2);
    }

    // 階乗
    static modint<MOD> factorial(ll n){
        modint<MOD> ret(1);
        if(n == 0) return ret;
        if((ll)factorial_vec.size() >= n) return factorial_vec[n-1];
        ret = factorial(n-1)*n;
        factorial_vec.push_back(ret);
        return ret;
    }

    // コンビネーション
    static modint<MOD> combination(ll n, ll r){
        return factorial(n) / factorial(r) / factorial(n-r);
    }

};

using mint = modint<MOD>;
template <ll MOD> vector<modint<MOD>> modint<MOD>::factorial_vec;

const int vmax = 250005;
mint fact[vmax],finv[vmax],invs[vmax];
void initfact(){
	fact[0]=1;
	rep(i,1,vmax){
		fact[i]=fact[i-1]*i;
	}
	finv[vmax-1]=mint::inv(fact[vmax-1]);
	for(int i=vmax-2;i>=0;i--){
		finv[i]=finv[i+1]*(i+1);
	}
	for(int i=vmax-1;i>=1;i--){
		invs[i]=finv[i]*fact[i-1];
	}
}
mint choose(int n,int k){
	return n-k >= 0?fact[n]*finv[n-k]*finv[k]:0;
}
mint binom(int a,int b){
	return 0<=a&&0<=b?fact[a+b]*finv[a]*finv[b]:0;
}
mint catalan(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}

template <class E, class V, E (*merge)(E, E), E (*e)(), E (*put_edge)(V, int), V (*put_vertex)(E, int)>
class RerootingDP
{
    int n, root, inner_edge_id;
    vector<E> outs;
    struct edge {
        int to, idx, xdi;
    };
    vector<edge> es;
    vector<int> start;

    int outs_start(int v){
        int res = start[v]-v;
        if(root < v) res++;
        return res;
    }

    void es_build(){
        vector<edge> nes(2*n-2);
        vector<int> nstart(n+2, 0);
        for(int i = 0; i < 2*n-2; i++){
            nstart[start[i]+2]++;
        }
        for(int i = 0; i < n; i++){
            nstart[i+1] += nstart[i];
        }
        for(int i = 0; i < 2*n-2; i++){
            nes[nstart[start[i]+1]++] = es[i];
        }
        swap(es, nes);
        swap(start, nstart);
    }
    
public:
    RerootingDP(int n_ = 0) : n(n_), inner_edge_id(0) {
        es.resize(2*n-2);
        start.resize(2*n-2);
        if(n == 1) es_build();
    }

    void add_edge(int u, int v, int idx, int xdi){ // u→v, v→uの有向辺をそれぞれ追加
        start[inner_edge_id] = u;
        es[inner_edge_id] = {v, idx, xdi};
        inner_edge_id++;
        start[inner_edge_id] = v;
        es[inner_edge_id] = {u, xdi, idx};
        inner_edge_id++;
        if(inner_edge_id == 2*n-2){
            es_build();
        }
    }

    vector<V> build(int root_ = 0){
        root = root_;
        vector<V> subdp(n); subdp[0] = put_vertex(e(), 0);
        outs.resize(n);
        vector<int> geta(n+1, 0);
        for(int i = 0; i < n; i++){
            geta[i+1] = start[i+1]-start[i]-1;
        }
        geta[root+1]++;
        for(int i = 0; i < n; i++){
            geta[i+1] += geta[i];
        }

        auto dfs = [&](auto sfs, int v, int f)-> void {
            E val = e();
            for(int i = start[v]; i < start[v+1]; i++){
                if(es[i].to == f){
                    swap(es[start[v+1]-1], es[i]);
                }
                if(es[i].to == f) continue;
                sfs(sfs, es[i].to, v);
                E nval = put_edge(subdp[es[i].to], es[i].idx);
                outs[geta[v]++] = nval;
                val = merge(val, nval);
            }
            subdp[v] = put_vertex(val, v);
        };
        dfs(dfs, root, -1);
        return subdp;
    }

    vector<V> reroot(){
        vector<E> reverse_edge(n);
        reverse_edge[root] = e();
        vector<V> answers(n);
        auto dfs = [&](auto sfs, int v) -> void {
            int le = outs_start(v);
            int ri = outs_start(v+1);
            int siz = ri-le;
            vector<E> rui(siz+1);
            rui[siz] = e();
            for(int i = siz-1; i >= 0; i--){
                rui[i] = merge(outs[le+i], rui[i+1]);
            }
            answers[v] = put_vertex(merge(rui[0], reverse_edge[v]), v);
            E lui = e();
            for(int i = 0; i < siz; i++){
                V rdp = put_vertex(merge(merge(lui, rui[i+1]), reverse_edge[v]), v);
                reverse_edge[es[start[v]+i].to] = put_edge(rdp, es[start[v]+i].xdi);
                lui = merge(lui, outs[le+i]);
                sfs(sfs, es[start[v]+i].to);
            }
        };
        dfs(dfs, root);
        return answers;
    }
};

using E = pair<mint, int>;
using V = pair<mint, int>;
ll m;
E merge(E a, E b){
    mint cnt = (a.first*b.first)*fact[a.second+b.second]*finv[a.second]*finv[b.second];
    return {cnt, a.second+b.second};
}
E e(){
    return {mint(1), 0};
}
E put_edge(V v, int i){
    return {v.first, v.second};
}
V put_vertex(E e, int v){
    return {e.first, e.second+1};
}

int main(){
    initfact();
    int n; cin >> n;
    RerootingDP<E, V, merge, e, put_edge, put_vertex> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g.add_edge(a, b, i, i);
    }
    g.build();
    vector<V> cnt = g.reroot();
    mint ans = 0;
    rep(i, 0, n) ans += cnt[i].first;
    cout << ans/2 << endl;

    
    return 0;
}