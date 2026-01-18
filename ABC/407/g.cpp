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
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<48;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// https://drken1215.hatenablog.com/entry/2023/07/15/192200

int main(){
    int h, w; cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    ll sum = 0;
    rep(i, 0, h) rep(j, 0, w){
        cin >> a[i][j];
        sum += a[i][j];
        a[i][j] = -a[i][j];
    }

    mcf_graph<ll, ll> g(h*w+2);
    int source = h*w, target = h*w+1;
    g.add_edge(source, target, h*w/2, INF); // バイパス
    rep(i, 0, h) rep(j, 0, w){
        if((i+j)%2 == 0){
            g.add_edge(source, i*w+j, 1, 0);
            rep(k, 0, 4){
                int ni = i+(k-1)%2, nj = j+(k-2)%2;
                if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
                if(a[i][j]+a[ni][nj] <= 0) continue;
                g.add_edge(i*w+j, ni*w+nj, 1, INF-(a[i][j]+a[ni][nj]));
            }
        }else{
            g.add_edge(i*w+j, target, 1, 0);
        }
    }

    auto [max_flow, min_cost] = g.flow(source, target, h*w/2);
    // cout << max_flow << ' ' << min_cost << endl;
    // cout << (INF*(h*w/2)-min_cost) << endl;
    cout << sum+(INF*max_flow-min_cost) << endl;

    
    return 0;
}