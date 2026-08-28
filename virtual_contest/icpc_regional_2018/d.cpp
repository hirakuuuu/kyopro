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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        int n; cin >> n;
        if(n == 0) break; 
        int m; cin >> m;
        vector<vector<int>> adj(n, vector<int>(n, -1));
        vector<int> win(n), lose(n);
        rep(i, 0, m){
            int x, y; cin >> x >> y;
            x--, y--;
            adj[x][y] = 1;
            adj[y][x] = 0;
            win[x]++;
            lose[y]++;
        }

        auto f = [&](auto self) -> int {
            int pi = -1, pj = -1;
            rep(i, 0, n){
                rep(j, i+1, n){
                    if(adj[i][j] == -1){
                        pi = i, pj = j;
                        break;
                    }
                }
                if(pi != -1) break;
            }

            if(pi == -1){
                rep(i, 0, n){
                    if(win[i] > n/2 || lose[i] > n/2){
                        return 0;
                    }
                }
                return 1;
            }

            int res = 0;
            if(win[pi] < n/2){
                adj[pi][pj] = 1;
                adj[pj][pi] = 0;
                win[pi]++;
                lose[pj]++;
                res += self(self);
                adj[pi][pj] = adj[pj][pi] = -1;
                win[pi]--;
                lose[pj]--;
            }
            if(lose[pi] < n/2){
                adj[pi][pj] = 0;
                adj[pj][pi] = 1;
                win[pj]++;
                lose[pi]++;
                res += self(self);
                adj[pi][pj] = adj[pj][pi] = -1;
                win[pj]--;
                lose[pi]--;
            }

            return res;
        };
        


        cout << f(f) << endl;



    }
    
    return 0;
}