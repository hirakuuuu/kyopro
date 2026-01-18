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
    int h, w, m; cin >> h >> w >> m;
    vector<string> s(h);
    int sx, sy, gx, gy;
    rep(i, 0, h){
        cin >> s[i];
        rep(j, 0, w){
            if(s[i][j] == 'S') sx = i, sy = j;
            if(s[i][j] == 'G') gx = i, gy = j;
        }
    }

    vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(m+1, -1)));
    queue<tuple<int, int, int>> que;
    dist[sx][sy][m] = 0;
    que.push({sx, sy, m});
    while(!que.empty()){
        auto [px, py, k] = que.front(); que.pop();
        rep(i, 0, 4){
            int nx = px+(i-1)%2, ny = py+(i-2)%2;
            int nk = k;
            if(!inr(0, nx, h) || !inr(0, ny, w)) continue;
            if(s[nx][ny] == '#') continue;
            if(inr(0, s[nx][ny]-'a', m) && (s[nx][ny]-'a') != k) continue;
            if(inr(0, s[nx][ny]-'1', m)) nk = s[nx][ny]-'1';
            if(dist[nx][ny][nk] != -1) continue;
            dist[nx][ny][nk] = dist[px][py][k]+1;
            que.push({nx, ny, nk});
        }
    }

    int ans = IINF;
    rep(i, 0, m+1){
        if(dist[gx][gy][i] == -1) continue;
        chmin(ans, dist[gx][gy][i]);
    }
    if(ans == IINF) ans = -1;
    cout << ans << endl;

    
    return 0;
}