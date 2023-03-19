#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc294/tasks/abc294_g

// https://wk1080id.hatenablog.com/entry/2020/05/30/004858
// https://ikatakos.com/pot/programming_algorithm/graph_theory/lowest_common_ancestor

vector<vector<ll>> g(200005); //グラフの隣接リスト
vector<ll> eular_tour; //オイラーツアーの頂点配列
vector<ll> depth; //木の深さ
vector<ll> ind(200005); //各頂点がオイラーツアー配列の何番目に最初に訪れるか

void dfs(int now, int par, int d){//今の頂点、親の頂点
    ind[now] = eular_tour.size();
    eular_tour.push_back(now);
    depth.push_back(d);
    for(int i = 0; i < g[now].size(); i++){
        if(g[now][i] != par){
            dfs(g[now][i],now, d+1);
            eular_tour.push_back(now);
            depth.push_back(d);
        }
    }
}

struct SegmentTree {
    private:
        int n;
        vector<pll> node;
    
    public:
        SegmentTree(vector<pll> a){
            // 配列のサイズを取得
            int sz = (int) a.size();
            // nはszを超える最小の2のべき乗
            n = 1;
            while(n < sz) n *= 2;
            // ノードの個数は2n-1
            node.resize(2*n-1, {iinf, iinf});

            // 再下段にaの値を格納
            rep(i, 0, sz) node[i+n-1] = a[i];
            // 親を更新
            for(int j = n-2; j >= 0; j--) node[j] = min(node[2*j+1], node[2*j+2]);
        }

        // // 更新処理
        // void update(int x, int val){
        //     // 再下段の指定した位置の値を更新
        //     x += n-1;
        //     chmin(node[x], val);
        //     // 親の値を更新しながら上る
        //     while(x > 0){
        //         x = (x-1)/2;
        //         chmin(node[x], val);
        //     }
        // }

        // 取得処理
        pll get_num(ll a, ll b, int k=0, int l=0, int r=-1){
            if(r < 0) r = n;
            if(r <= a or b <= l) return {iinf, iinf};
            if(a <= l and r <= b) return node[k];

            pll v1 = get_num(a, b, 2*k+1, l, (l+r)/2);
            pll v2 = get_num(a, b, 2*k+2, (l+r)/2, r);
            return min(v1, v2);
        }
};

class BIT {
public:
    ll n; // データの長さ
    vector<ll> a; // データの格納先

    BIT(ll n_): n(n_), a(n_+1, 0){} // コンストラクタ

    // a[i]をxに加算する
    void add(ll pos, ll x){
        pos++; // 1インデックスにしてる
        while(pos <= n){
            a[pos] += x;
            pos += pos&(-pos);
        }
    }

    // [0, i]を求める
    ll sum_sub(ll pos){
        pos++;
        ll res = 0;
        while(0 < pos){
            res += a[pos];
            pos -= pos&(-pos);
        }
        return res;
    }

    // [l, r]の和
    ll sum(ll l, ll r){
        return sum_sub(r)-sum_sub(l-1);
    }

    // a[0]+a[1]+...+a[i] >= x となる最小のiを求める（任意のkでa[k]>=0が必要）
    ll lower_bound(ll x){
        if(x <= 0){
            return 0;
        }else{
            ll i = 0, len = 1;

            //最大としてありうる区間の長さを取得する
            //n以下の最小の二乗のべき(BITで管理する数列の区間で最大のもの)を求める
            while(len < n) len *= 2;

            //区間の長さは調べるごとに半分になる
            while(0 < len){
                //その区間を採用する場合
                if(i+len < n and a[i+len] < x){
                    x -= a[i+len];
                    i += len;
                }
            }
            return i;
        }
    }

};

void print(vector<ll> a){
    for(const auto &aa: a){
        cout << aa << ' ';
    }
    cout << endl;
}


int main(){
    int n; cin >> n;
    vector<ll> u(n), v(n), w(n);
    map<pll, ll> edgeid;
    rep(i, 0, n-1){
        cin >> v[i] >> u[i] >> w[i];
        u[i]--; v[i]--;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
        edgeid[{u[i], v[i]}] = edgeid[{v[i], u[i]}] = i;
    }
    // オイラーツアー構築
    dfs(0, -1, 0);
    // print(eular_tour);
    // print(depth);
    // rep(i, 0, n){
    //     cout << ind[i] << ' ';
    // }
    // cout << endl;


    vector<ll> cost(eular_tour.size()-1);
    vector<vector<ll>> eular_edge_id(n-1);
    rep(i, 0, eular_tour.size()-1){
        cost[i] = w[edgeid[{eular_tour[i], eular_tour[i+1]}]];
        eular_edge_id[edgeid[{eular_tour[i], eular_tour[i+1]}]].push_back(i);
        if(depth[i] > depth[i+1]) cost[i] *= -1;
    }

    BIT bit(eular_tour.size());
    rep(i, 0, eular_tour.size()-1) bit.add(i+1, cost[i]);

    vector<pll> vd(eular_tour.size());
    rep(i, 0, eular_tour.size()){
        vd[i] = {depth[i], eular_tour[i]};
    }
    SegmentTree st(vd);

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            ll i, nw; cin >> i >> nw;
            i--;
            w[i] = nw;
            for(const auto &eid: eular_edge_id[i]){
                if(cost[eid] > 0){
                    bit.add(eid+1, -cost[eid]+nw);
                    cost[eid] = nw;
                }else{
                    bit.add(eid+1, -cost[eid]-nw);
                    cost[eid] = -nw;
                } 
            }
            // print(cost);
        }else{
            ll nu, nv; cin >> nu >> nv;
            nu--, nv--;
            ll iu = ind[nu], iv = ind[nv];
            if(iu > iv) swap(iu, iv);
            ll lca = st.get_num(iu, iv+1).second;
            // cout << lca << endl;
            // cout << bit.sum_sub(iu) << endl;
            // cout << iv << endl;
            cout << bit.sum_sub(iu)+bit.sum_sub(iv)-2*bit.sum_sub(ind[lca]) << endl;
        }

    }



    




    
    return 0;
}