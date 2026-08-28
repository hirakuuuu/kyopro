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
    int n; cin >> n;
    vector<vector<int>> g(n+1);
    rep(i, 0, n){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
    }

    int ans = 0;
    int mi = IINF; 
    rep(i, 1, n+1){
        for(auto y: g[i]){
            if(mi >= y){
                ans++;
            }
        }
        for(auto y: g[i]){
            chmin(mi, y);
        }
    }
    cout << ans << endl;
    return 0;
}