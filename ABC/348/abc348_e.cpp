#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

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

using E = pair<ll, ll>;
using V = pair<ll, ll>;
vector<ll> c;
E merge(E a, E b){
    return {a.first+b.first, a.second+b.second};
}
E e(){
    return E({0, 0});
}
E put_edge(V v, int i){
    return {v.first+v.second, v.second};
}
V put_vertex(E e, int v){
    return {e.first, e.second+c[v]};
}


int main(){
    int n; cin >> n;
    RerootingDP<E, V, merge, e, put_edge, put_vertex> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g.add_edge(a, b, i, i);
    }
    c.resize(n);
    rep(i, 0, n) cin >> c[i];
    g.build();
    vector<pair<ll, ll>> f = g.reroot();
    ll ans = INF;
    rep(i, 0, n){
        chmin(ans, f[i].first);
    }
    cout << ans << endl;
    
    return 0;
}