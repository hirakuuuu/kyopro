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
    int h, w; cin >> h >> w;
    int si, sj; cin >> si >> sj;
    int gi, gj; cin >> gi >> gj;

    vector<vector<int>> block(h+2, vector<int>(w+2));
    rep(i, 0, w+2) block[0][i] = block[h+1][i] = 1;
    rep(i, 0, h+2) block[i][0] = block[i][w+1] = 1;

    int ans = 0;
    auto dfs = [&](auto self, int px, int py) -> void {
        // cout << px << ' ' << py << endl;
        // rep(i, 0, h){
        //     rep(j, 0, w){
        //         cout << block[i+1][j+1];
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        if(px == gi && py == gj){
            ans++;
            return;
        }
        rep(k, 0, 4){
            int nx = px+(k-1)%2, ny = py+(k-2)%2;
            if(block[nx][ny]) continue;
            block[px][py] = 1;
            vector<int> pre(4);
            rep(l, 0, 4){
                int ax = px+(l-1)%2, ay = py+(l-2)%2;
                pre[l] = block[ax][ay];
                if(l != k) block[ax][ay] = 1;
            }
            self(self, nx, ny);
            rep(l, 0, 4){
                int ax = px+(l-1)%2, ay = py+(l-2)%2;
                block[ax][ay] = pre[l];
            }
            block[px][py] = 0;
        }
    };
    dfs(dfs, si, sj);
    cout << ans << endl;
    
    return 0;
}