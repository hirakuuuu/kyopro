#include <bits/stdc++.h>
#include <unordered_map>
#include <stdlib.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(ll i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
//constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll gcd(ll a, ll b){
    if(a%b == 0){
      return b;
    }else{
      return gcd(b, a%b);
    }
}

ll lcm(ll a, ll b){
    return a*b / gcd(a, b);
}

ll powMod(ll x, ll n) {
    if (n == 0) return 1 % MOD;
    ll val = powMod(x, n / 2);
    val *= val;
    val %= MOD;
    if (n % 2 == 1) val *= x;
    return val % MOD;
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


string x;

struct Node {
    int val;
    int id;
    Node(int val=0, int id=-1): val(val), id(id){};
};

using E = pair<pair<Node, Node>, pair<Node, Node>>;

using V = pair<Node, Node>;
ll m;
E merge(E a, E b){
    Node n1, n2, n3, n4;

    if(a.first.first.val > b.first.first.val) n1 = a.first.first;
    else n1 = b.first.first;


    if(a.first.second.val > b.first.second.val) n2 = a.first.second;
    else n2 = b.first.second;

    if(a.first.first.id != n1.id && a.first.first.val > n3.val) n3 = a.first.first;
    if(a.second.first.id != n1.id && a.second.first.val > n3.val) n3 = a.second.first;
    if(b.first.first.id != n1.id && b.first.first.val > n3.val) n3 = b.first.first;
    if(b.second.first.id != n1.id && b.second.first.val > n3.val) n3 = b.second.first;


    if(a.first.second.id != n2.id && a.first.second.val > n4.val) n4 = a.first.second;
    if(a.second.second.id != n2.id && a.second.second.val > n4.val) n4 = a.second.second;
    if(b.first.second.id != n2.id && b.first.second.val > n4.val) n4 = b.first.second;
    if(b.second.second.id != n2.id && b.second.second.val > n4.val) n4 = b.second.second;

    return {{n1, n2}, {n3, n4}};
}
E e(){
    Node n1, n2, n3(0, -1), n4(0, -1);
    return {{n1, n2}, {n3, n4}};
}
E put_edge(V v, int i){
    // cout << i << ' ' << ' ' << v.first.val << ' ' << v.first.id << ' '  << v.second.val << ' ' << v.second.id  << endl;
    Node n1 = v.first;
    Node n2 = v.second;
    Node n3(0, -1), n4(0, -1);
    return {{n1, n2}, {n3, n4}};
}
V put_vertex(E e, int v){
    if(x[v] == '1'){
        return {Node(1, v), Node(max(e.first.second.val, e.second.second.val)+1, v)};
    }

    // cout << "##################################" << endl;
    // cout << v << endl;
    // cout << e.first.first.id << ' ' << e.first.first.val << endl;
    // cout << e.second.first.id << ' ' << e.second.first.val << endl;
    // cout << e.first.second.id << ' ' << e.first.second.val << endl;
    // cout << e.second.second.id << ' ' << e.second.second.val << endl;
    // cout << "##################################" << endl;

    Node n1(e.first.first.val+2, v);
    if(e.first.first.id < 0){
        n1.val = 1;
    }

    Node n2(1, v);
    if(e.first.first.id >= 0) chmax(n2.val, e.first.first.val+2);
    if(e.second.first.id >= 0) chmax(n2.val, e.second.first.val+2);
    if(e.first.second.id >= 0) chmax(n2.val, e.first.second.val+1);
    if(e.second.second.id >= 0) chmax(n2.val, e.second.second.val+1);

    if(e.first.first.id >= 0 && e.first.second.id >= 0){
        if(e.first.first.val == 1 && x[e.first.first.id] == '2') chmax(n2.val, e.first.first.val+e.first.second.val+2);
        if(e.first.first.id != e.first.second.id) chmax(n2.val, e.first.first.val+e.first.second.val+2);
    }
    if(e.first.first.id >= 0 && e.second.second.id >= 0){
        if(e.first.first.val == 1 && x[e.first.first.id] == '2') chmax(n2.val, e.first.first.val+e.second.second.val+2);
        if(e.first.first.id != e.second.second.id) chmax(n2.val, e.first.first.val+e.second.second.val+2);
    }
    if(e.second.first.id >= 0 && e.first.second.id >= 0){
        if(e.second.first.val == 1 && x[e.second.first.id] == '2') chmax(n2.val, e.second.first.val+e.first.second.val+2);
        if(e.second.first.id != e.first.second.id) chmax(n2.val, e.second.first.val+e.first.second.val+2);
    }
    if(e.second.first.id >= 0 && e.second.second.id >= 0){
        if(e.second.first.val == 1 && x[e.second.first.id] == '2') chmax(n2.val, e.second.first.val+e.second.second.val+2);
        if(e.second.first.id != e.second.second.id) chmax(n2.val, e.second.first.val+e.second.second.val+2);
    }
    
    return {n1, n2};
}


int main() {
    while(true){
        int n; cin >> n;
        if(n == 0) break;
        cin >> x;
        RerootingDP<E, V, merge, e, put_edge, put_vertex> g(n);
        rep(i, 1, n){
            int p; cin >> p;
            p--;
            g.add_edge(p, i, i-1, i-1);
        }

        g.build();
        vector<V> val = g.reroot();
        int ans = 0;
        rep(i, 0, n){
            cout << i << ' ' << val[i].first.val << ' ' << val[i].second.val << endl;
            chmax(ans, max(val[i].first.val, val[i].second.val));
        }
        cout << ans << endl;
    }

    return 0;
}