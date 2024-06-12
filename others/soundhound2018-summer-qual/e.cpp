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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n);
    rep(i, 0, m){
        int u, v;
        ll s; cin >> u >> v >> s;
        u--, v--;
        g[u].push_back({v, s});
        g[v].push_back({u, s});
    }

    vector<pair<ll, ll>> a(n, {-1, -1});
    vector<int> dist(n, -1);
    a[0] = {1, 0};
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int q = que.front(); que.pop();
        for(auto [nq, sum]: g[q]){
            if(dist[nq] != -1){
                ll A = a[nq].first+a[q].first;
                ll B = a[nq].second+a[q].second;
                if((A == 0 && B != sum) || (A != 0 && (sum-B)%2 != 0)){
                    cout << 0 << endl;
                    return 0;
                }
            }else{
                a[nq].first = -a[q].first;
                a[nq].second = sum-a[q].second;
                dist[nq] = 1-dist[q];
                que.push(nq);
            }
        }
    }

    // 奇数長のサイクルがあると答えが一意に定まる
    // 両端点の距離の偶奇が同じ辺があれば良い
    bool is_odd_cycle = false;
    rep(i, 0, n){
        for(auto [v, s]: g[i]){
            if(a[i].first == a[v].first) is_odd_cycle = true;
        }
    }

    if(is_odd_cycle){
        // 全て正の整数にできるか
        set<ll> x;
        rep(i, 0, n){
            for(auto [v, s]: g[i]){
                if(a[i].first == a[v].first){
                    ll A = a[i].first+a[v].first;
                    ll B = a[i].second+a[v].second;
                    x.insert((s-B)/A);
                }
            }
        }
        // 解が一意に定まる必要がある
        ll ans = (x.size() == 1);
        rep(i, 0, n){
            if(a[i].first*(*x.begin())+a[i].second <= 0) ans = 0;
        }
        cout << ans << endl;
    }else{
        // 二部グラフ
        // 奇数、偶数で最大、最小を求める
        ll mx = INF, mi = -INF;
        rep(i, 0, n){
            if(a[i].first == 1) chmax(mi, -a[i].second+1);
            else chmin(mx, a[i].second-1);
        }
        ll ans = max(0LL, mx-mi+1);
        cout << ans << endl;
    }
    
    return 0;
}