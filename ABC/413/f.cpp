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
    int h, w, k; cin >> h >> w >> k;
    ll ans = 0;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    vector<vector<int>> cnt(h, vector<int>(w));
    queue<pair<int, int>> que;
    rep(i, 0, k){
        int r, c; cin >> r >> c; r--, c--;
        que.push({r, c});
        dist[r][c] = 0;
        cnt[r][c] = 4;
    }

    while(!que.empty()){
        auto [r, c] = que.front(); que.pop();
        rep(i, 0, 4){
            int nr = r+(i-1)%2, nc = c+(i-2)%2;
            if(!inr(0, nr, h) || !inr(0, nc, w)) continue;
            if(dist[nr][nc] != -1) continue;
            cnt[nr][nc]++;
            if(cnt[nr][nc] == 2){
                dist[nr][nc] = dist[r][c]+1;
                ans += dist[nr][nc];
                que.push({nr, nc});
            }
        }
    }
    cout << ans << endl;
    return 0;
}