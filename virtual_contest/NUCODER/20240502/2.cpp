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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int h, w; cin >> h >> w;
    vector<vector<char>> s(h+2, vector<char>(w+2, '#'));
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            cin >> s[i][j];
        }
    }
    int ans = 0;
    rep(si, 1, h+1){
        rep(sj, 1, w+1){
            if(s[si][sj] == '#') continue;
            vector<vector<int>> seen(h+2, vector<int>(w+2, -1));
            queue<pair<int, int>> que;
            que.push({si, sj});
            seen[si][sj] = 0;
            while(!que.empty()){
                auto [ci, cj] = que.front(); que.pop();
                rep(k, 0, 4){
                    int ni = ci+(k-1)%2, nj = cj+(k-2)%2;
                    if(s[ni][nj] == '#' || seen[ni][nj] != -1) continue;
                    seen[ni][nj] = seen[ci][cj]+1;
                    chmax(ans, seen[ni][nj]);
                    que.push({ni, nj});
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}