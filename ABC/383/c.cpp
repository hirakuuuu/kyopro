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
    int h, w, d; cin >> h >> w >> d;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    vector<vector<int>> dist(h, vector<int>(w, IINF));
    queue<pair<int, int>> que;
    rep(i, 0, h) rep(j, 0, w){
        if(s[i][j] == 'H'){
            que.push({i, j});
            dist[i][j] = d;
        }
    }

    while(!que.empty()){
        auto [pi, pj] = que.front(); que.pop();
        if(dist[pi][pj] == 0) continue;
        rep(k, 0, 4){
            int ni = pi+(k-1)%2, nj = pj+(k-2)%2;
            if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
            if(s[ni][nj] == '#') continue;
            if(dist[ni][nj] != IINF) continue;
            dist[ni][nj] = dist[pi][pj]-1;
            que.push({ni, nj});
        }
    }
    
    int ans = 0;
    rep(i, 0, h) rep(j, 0, w){
        if(dist[i][j] == IINF) continue;
        ans++;
    }
    cout << ans << endl;




    return 0;
}