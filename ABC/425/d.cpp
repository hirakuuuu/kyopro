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
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    queue<pair<int, int>> que;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    rep(i, 0, h) rep(j, 0, w){
        if(s[i][j] == '#'){
            que.push({i, j});
            dist[i][j] = 0;
        }
    }

    while(!que.empty()){
        auto [px, py] = que.front(); que.pop();
        rep(k, 0, 4){
            int nx = px+(k-1)%2, ny = py+(k-2)%2;
            if(!inr(0, nx, h) || !inr(0, ny, w)) continue;
            if(dist[nx][ny] != -1) continue;
            int cnt_min = 0, mi = IINF;
            rep(nk, 0, 4){
                int nnx = nx+(nk-1)%2, nny = ny+(nk-2)%2;
                if(!inr(0, nnx, h) || !inr(0, nny, w)) continue;
                if(dist[nnx][nny] == -1) continue;
                if(mi > dist[nnx][nny]){
                    mi = dist[nnx][nny];
                    cnt_min = 1;
                }else if(mi == dist[nnx][nny]){
                    cnt_min++;
                }
            }
            if(cnt_min == 1){
                dist[nx][ny] = dist[px][py]+1;
                s[nx][ny] = '#';
                que.push({nx, ny});
            }
        }
    }

    int ans = 0;
    rep(i, 0, h) rep(j, 0, w){
        if(s[i][j] == '#') ans++;
    }
    cout << ans << endl;

    // rep(i, 0, h){
    //     cout << s[i] << endl;
    //     cout << endl;
    // }
    
    return 0;
}