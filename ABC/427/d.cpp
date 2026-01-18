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
    int t; cin >> t;
    vector<vector<int>> memo(200005, vector<int>(21));
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        string s; cin >> s;
        vector<vector<int>> g(n);
        rep(i, 0, m){
            int u, v; cin >> u >> v; u--, v--;
            g[u].push_back(v);
        }
        rep(i, 0, n){
            rep(j, 0, 2*k+1){
                memo[i][j] = -1;
            }
        }

        auto f = [&](auto self, int pos, int rest) -> int {
            if(memo[pos][rest] != -1) return memo[pos][rest];
            if(rest == 0){
                if(s[pos] == 'A') return memo[pos][rest] = 1;
                return memo[pos][rest] = 0;
            }

            int res = 1;
            {
                // res = 1;
                for(auto nxt: g[pos]){
                    res &= self(self, nxt, rest-1);
                }
                res = 1-res;
            }
            // cout << pos << ' ' << rest << ' ' << res << endl;

            return memo[pos][rest] = res;
        };

        if(f(f, 0, 2*k)) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    
    return 0;
}