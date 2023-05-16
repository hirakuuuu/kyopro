#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int mod = 1000000007;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc062/tasks/arc062_d

struct BiconnectedComponent {
    vector<int> ord;                   // 頂点に番号付け（行きがけ順） 
    vector<int> low;                   // どの連結成分に属するか
    vector<bool> used;                 // 探索済みかどうか
    vector<vector<int>> g;             // グラフの隣接リスト表現
    vector<vector<pair<int, int>>> bc; // 成分ごとに辺を格納するリスト
    vector<pair<int, int>> tmp;        // 一時的に辺を格納するリスト
    int n, k = 0;
    BiconnectedComponent(const vector<vector<int>> &g_) : g(g_) {
            n = (int)g.size();
            ord.resize(n, -1);
            low.resize(n, -1);
            used.resize(n, false);
    }
    void dfs(int u, int prev) {
        used[u] = true; // 探索済みにする
        ord[u] = k ++;  // 行きがけ順にナンバリング
        low[u] = ord[u]; // 自分自身のみを含む連結成分として記録
        for (auto v : g[u]){
            if (v == prev) continue; // 一つ前の頂点であれば飛ばす

            if (ord[v] < ord[u]) tmp.emplace_back(min(u, v), max(u, v)); // まだ探索してないor 前に探索した頂点に向かう辺であれば、辺を保存
            
            if (!used[v]) { // 探索していない場合
                dfs(v, u);
                low[u] = min(low[u], low[v]); // uとvを同じ連結成分に属するようにする
                if (low[v] >= ord[u]) { // vが属する連結成分の代表元がuより後に探索した頂点であるとき
                    // uを代表元とする連結成分が取得できる
                    bc.push_back({});
                    while (true) {
                        pair<int, int> e = tmp.back();
                        bc.back().emplace_back(e);
                        tmp.pop_back();
                        if (min(u, v) == e.first && max(u, v) == e.second) { // (u, v)までの辺が連結成分に属する
                            break;
                        }
                    }
                }
            }else{ // vが探索済みである場合
                low[u] = min(low[u], ord[v]); // 閉路ができたので、uとvを連結にする
            }
        }
    }
};

// 繰り返し二乗法
ll power(ll a, ll b, ll m=1000000007){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

vector<ll> fac(1005), inv(1005), finv(1005);

void init_fac(){
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    rep(i, 2, 1005){
        fac[i] = fac[i-1]*i%mod;
        inv[i] = mod-mod/i*inv[mod%i]%mod;
        finv[i] = finv[i-1]*inv[i]%mod;
    }
}

ll nCr(ll n, ll r){
    if(n < 0 or n-r < 0 or r < 0) return 0;
    return fac[n]*(finv[n-r]*finv[r]%mod)%mod;
}

ll nHr(ll n, ll r){
    return nCr(n+r-1, r);
}

int main(){
    init_fac();
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if(k == 1){
        cout << 1 << endl;
        return 0;
    }

    BiconnectedComponent components(g);
    rep(i, 0, n){
        if(components.used[i]) continue;
        components.dfs(i, -1);
    }
    


    ll ans = 1;
    for(auto comp: components.bc){
        ll sub_ans = 0;
        set<int> s;
        for(auto edge: comp){
            s.insert(edge.first);
            s.insert(edge.second);
        }
        ll l = comp.size();
        ll node = s.size();
        if(l == 1){
            sub_ans = k;
        }else if(node < l){
            sub_ans = nHr(l+1, k-1);
        }else{
            rep(i, 0, node){
                sub_ans += power(k, gcd(node, i));
                sub_ans %= mod;
            }
            sub_ans *= power(node, mod-2);
            sub_ans %= mod;
        }

        ans *= sub_ans;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}