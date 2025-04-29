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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    
    auto f = [&](auto self, int pos, int pre) -> vector<vector<mint>> {
        vector<vector<mint>> res(2, vector<mint>(n+1));
        res[0][0] = 1;
        res[1][1] = 1;

        for(auto nxt: g[pos]){
            if(pre == nxt) continue;
            vector<vector<mint>> nres = self(self, nxt, pos);
            rep(i, 0, 2){
                res = convolution(res[0], nres[0]);
            }
        }

    }
    return 0;
}