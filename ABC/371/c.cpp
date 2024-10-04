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
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n)), h(n, vector<int>(n));
    int mg; cin >> mg;
    rep(i, 0, mg){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u][v] = g[v][u] = 1;
    }
    int mh; cin >> mh;
    rep(i, 0, mh){
        int u, v; cin >> u >> v;
        u--, v--;
        h[u][v] = h[v][u] = 1;
    }

    vector<vector<int>> a(n, vector<int>(n));
    rep(i, 0, n){
        rep(j, i+1, n){
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    int ans = IINF;
    do{
        int tmp = 0;
        rep(i, 0, n){
            rep(j, i+1, n){
                if(g[i][j] != h[p[i]][p[j]]){
                    tmp += a[p[i]][p[j]];
                }
            }
        }
        chmin(ans, tmp);
    }while(next_permutation(p.begin(), p.end()));

    cout << ans << endl;
    return 0;
}