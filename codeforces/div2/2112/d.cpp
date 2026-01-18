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
    while(t--){
        int n; cin >> n;
        vector<vector<int>> g(n);
        vector<int> u(n-1), v(n-1);
        rep(i, 0, n-1){
            cin >> u[i] >> v[i]; u[i]--, v[i]--;
            g[u[i]].push_back(v[i]);
            g[v[i]].push_back(u[i]);
        }

        if(n == 2){
            cout << "NO" << endl;
            continue;
        }

        int root = -1;
        rep(i, 0, n){
            if(g[i].size() == 2){
                root = i;
                break;
            }
        }
        if(root == -1){
            cout << "NO" << endl;
            continue;
        }
        vector<pair<int, int>> edge;
        edge.push_back({g[root][0], root});
        edge.push_back({root, g[root][1]});
        auto f = [&](auto self, int pos, int pre, int d) -> void {
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                if(d == 0){
                    edge.push_back({pos, nxt});
                }else{
                    edge.push_back({nxt, pos});
                }
                self(self, nxt, pos, 1-d);
            }
        };
        f(f, g[root][0], root, 0);
        f(f, g[root][1], root, 1);
        cout << "YES" << endl;
        for(auto [a, b]: edge){
            cout << a+1 << ' ' << b+1 << endl;
        }
    }
    return 0;
}