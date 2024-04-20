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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
最大マッチング
*/

int main(){
    int n, t; cin >> n >> t;
    vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};
    vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};
    vector<pair<int, int>> a(n), b(n);
    rep(i, 0, n) cin >> a[i].first >> a[i].second;
    map<pair<int, int>, int> id_b;
    rep(i, 0, n){
        cin >> b[i].first >> b[i].second;
        id_b[b[i]] = i;
    }

    mf_graph<int> g(2*n+2);
    int source = 2*n, target = 2*n+1;
    rep(i, 0, n){
        rep(j, 0, 8){
            pair<int, int> na = {a[i].first+t*dx[j], a[i].second+t*dy[j]};
            if(id_b.find(na) == id_b.end()) continue;
            g.add_edge(i, id_b[na]+n, 1);
        }
    }
    rep(i, 0, n){
        g.add_edge(source, i, 1);
        g.add_edge(i+n, target, 1);
    }
    int fl = g.flow(source, target);
    if(fl < n){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    vector<int> d(n, -1);
    int id = 0;
    rep(i, 0, n){
        rep(j, 0, 8){
            pair<int, int> na = {a[i].first+t*dx[j], a[i].second+t*dy[j]};
            if(id_b.find(na) == id_b.end()) continue;
            // 最大マッチングを調べるには、フローを流した後の辺の状態をチェック
            // 容量は１なので、使われていればマッチングに含めてOK
            auto e = g.get_edge(id);
            if(e.flow > 0) d[e.from] = j+1;
            id++;
        }
    }
    rep(i, 0, n) cout << d[i] << ' ';
    cout << endl;




    return 0;
}