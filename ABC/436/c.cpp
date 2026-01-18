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
    set<pair<int, int>> block;
    int ans = 0;
    rep(i, 0, m){
        int r, c; cin >> r >> c;
        vector<pair<int, int>> bs = {
            {r, c},
            {r+1, c},
            {r, c+1},
            {r+1, c+1}
        };
        bool ok = true;
        rep(k, 0, 4){
            if(block.count(bs[k])) ok = false;
        }
        if(ok){
            rep(k, 0, 4){
                block.insert(bs[k]);
            }
            ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}