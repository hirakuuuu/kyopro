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
    vector<vector<int>> edge(n, vector<int>(n));
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    int ans = 0;
    do{
        if(p[0] != 0) break;
        bool ok = true;
        rep(i, 1, n){
            if(edge[p[i-1]][p[i]]) continue;
            ok = false;
            break;
        }
        ans += ok;
    }while(next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    return 0;
}