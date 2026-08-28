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
        rep(i, 0, n-1){
            int a, b; cin >> a >> b; a--, b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> deg(n);
        rep(i, 0, n) deg[i] = (int)g[i].size();

        // cout << "AAAAAAAAA" << endl;
        // 次数4以上の頂点からなる木を作る
        vector<vector<int>> g4(n);
        vector<vector<int>> g3(n);
        rep(i, 0, n){
            for(auto j: g[i]){
                if(deg[i] >= 4 && deg[j] >= 4){
                    g4[i].push_back(j);
                }
                if(deg[j] == 3){
                    g3[i].push_back(j);
                }
            }
        }



        int ans = 0;
        { // 1
            rep(i, 0, n){
                if(deg[i] >= 2) ans = 1;
            }
        }
        { // 2
            rep(i, 0, n){
                for(auto j: g[i]){
                    if(deg[i] >= 3 && deg[j] >= 3) ans = 2;
                }
            }
        }

        vector<int> seen(n);
        rep(i, 0, n){
            if(deg[i] < 4) continue;
            if(seen[i]) continue;
            
            auto f = [&](auto self, int pos, int pre) -> pair<int, int> {
                seen[pos] = 1;
                int cnt = 0;
                if(g3[pos].size() >= 2) cnt = 2;
                else if(g3[pos].size() >= 1) cnt = 1;

                
                pair<int, int> res = {1, 1};
                if(cnt == 2) res = {2, 3};
                else if(cnt == 1) res = {2, 2};

                for(auto nxt: g4[pos]){
                    if(nxt == pre) continue;
                    auto [t1, t2] = self(self, nxt, pos);
                    chmax(res.second, t1+res.first);
                    chmax(res.second, t2);
                    chmax(res.first, t1+1);
                }
                // cout << pos << ' ' << pre << ' ' << res.first << ' ' << res.second << endl;

                return res;
            };

            chmax(ans, f(f, i, -1).second);
        }
        cout << ans << endl;
    }
    
    return 0;
}