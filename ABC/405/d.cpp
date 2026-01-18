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


    vector<vector<int>> dist(h, vector<int>(w, -1));
    vector<vector<pair<int, int>>> to(h, vector<pair<int, int>>(w, {-1, -1}));

    queue<pair<int, int>> que;
    rep(i, 0, h) rep(j, 0, w){
        if(s[i][j] == 'E'){
            que.push({i, j});
            dist[i][j] = 0;
        }
    }
    string y = "v>^<";

    vector<string> ans = s;
    while(!que.empty()){
        auto [i, j] = que.front(); que.pop();
        rep(k, 0, 4){
            int ni = i+(k-1)%2, nj = j+(k-2)%2;
            if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
            if(s[ni][nj] == '#') continue;
            if(dist[ni][nj] != -1) continue;
            dist[ni][nj] = dist[i][j]+1;
            ans[ni][nj] = y[k];
            que.push({ni, nj});
        }
    }

    rep(i, 0, h) cout << ans[i] << endl;
    
    return 0;
}