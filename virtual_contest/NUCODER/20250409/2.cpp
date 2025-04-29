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
    rep(i, 0, h){
        cin >> s[i];
    }

    vector<vector<bool>> can_move(h, vector<bool>(w, true));
    rep(i, 0, h) rep(j, 0, w){
        if(s[i][j] == '#') continue;
        rep(k, 0, 4){
            int ni = i+(k-1)%2, nj = j+(k-2)%2;
            if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
            if(s[ni][nj] == '#') can_move[i][j] = false;
        }
    }

    vector<vector<pair<int, int>>> seen(h, vector<pair<int, int>>(w, {-1, -1}));
    int ans = 1;
    rep(i, 0, h){
        rep(j, 0, w){
            if(s[i][j] == '#') continue;
            if(!can_move[i][j]) continue;
            if(seen[i][j].first != -1) continue;

            queue<pair<int, int>> que;
            que.push({i, j});
            seen[i][j] = {i, j};
            int tmp = 0;
            while(!que.empty()){
                tmp++;
                auto [pi, pj] = que.front(); que.pop();
                if(!can_move[pi][pj]) continue;
                rep(k, 0, 4){
                    int ni = pi+(k-1)%2, nj = pj+(k-2)%2;
                    if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
                    if(s[ni][nj] == '#') continue;
                    if(!can_move[ni][nj]){
                        if(seen[ni][nj] != make_pair(i, j)){
                            tmp++;
                            seen[ni][nj] = {i, j};
                        }
                    }else{
                        if(seen[ni][nj].first != -1) continue;
                        seen[ni][nj] = {i, j};
                        que.push({ni, nj});
                    }
                }
            }
            chmax(ans, tmp);
        }
    }
    cout << ans << endl;

    return 0;
}
