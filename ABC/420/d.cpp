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
    vector<string> a(h);
    int sx, sy, gx, gy;
    rep(i, 0, h){
        cin >> a[i];
        rep(j, 0, w){
            if(a[i][j] == 'S'){
                sx = i, sy = j;
            }else if(a[i][j] == 'G'){
                gx = i, gy = j;
            }
        }
    }

    queue<tuple<int, int, int>> que;
    vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(2, IINF)));
    dist[sx][sy][0] = 0;
    que.push({sx, sy, 0});
    while(!que.empty()){
        auto [px, py, oe] = que.front(); que.pop();
        rep(k, 0, 4){
            int nx = px+(k-1)%2, ny = py+(k-2)%2;
            int noe = oe;
            if(!inr(0, nx, h) || !inr(0, ny, w)) continue;
            if(a[nx][ny] == '#') continue;
            if(a[nx][ny] == 'o' && oe == 1) continue;
            if(a[nx][ny] == 'x' && oe == 0) continue;
            if(a[nx][ny] == '?') noe = 1-noe;
            if(dist[nx][ny][noe] == IINF){
                dist[nx][ny][noe] = dist[px][py][oe]+1;
                que.push({nx, ny, noe});
            }
        }
    }

    int ans = min(dist[gx][gy][0], dist[gx][gy][1]);
    if(ans == IINF) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}