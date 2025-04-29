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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    int ans = 0;
    map<pair<int, int>, bool> used;
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        if(u == v){
            ans++;
        }else{
            if(u > v) swap(u, v);
            if(used[{u, v}]) ans++;
            else used[{u, v}] = true;
        }
    }
    cout << ans << endl;
    return 0;
}