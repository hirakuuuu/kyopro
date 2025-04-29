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

    int sh, sw, gh, gw;
    rep(i, 0, h){
        rep(j, 0, w){
            if(s[i][j] == 'S') sh = i, sw = j;
            if(s[i][j] == 'G') gh = i, gw = j;
        }
    }

    queue<tuple<int, int, int>> que;
    que.push({sh, sw, 0});
    que.push({sh, sw, 1});
    vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(2, IINF)));
    dist[sh][sw][0] = dist[sh][sw][1] = 0;
    while(!que.empty()){
        auto [ch, cw, pre] = que.front(); que.pop();
        rep(k, 0, 4){
            int nh = ch+(k-1)%2, nw = cw+(k-2)%2;
            if(!inr(0, nh, h) || !inr(0, nw, w)) continue;
            if(s[nh][nw] == '#') continue;
            if(dist[nh][nw][k%2] != IINF) continue;
            if(pre == k%2) continue;
            dist[nh][nw][k%2] = dist[ch][cw][pre]+1;
            que.push({nh, nw, k%2});
        }
    }
    int ans = min(dist[gh][gw][0], dist[gh][gw][1]);
    if(ans == IINF) ans = -1;
    cout << ans << endl;

    return 0;
}