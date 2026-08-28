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
    vector<string> s(h+2);
    rep(j, 0, w+2){
        s[0] += '.';
        s[h+1] += '.';
    }
    rep(i, 1, h+1){
        s[i] += '.';
        string t; cin >> t;
        s[i] += t;
        s[i] += '.';
    }

    vector<vector<int>> col(h+2, vector<int>(w+2, -1));
    int cnt = 0;
    rep(i, 0, h+2){
        rep(j, 0, w+2){
            if(s[i][j] == '#') continue;
            if(col[i][j] != -1) continue;
            col[i][j] = cnt;
            queue<pair<int, int>> que;
            que.push({i, j});
            while(!que.empty()){
                auto [pi, pj] = que.front(); que.pop();
                rep(k, 0, 4){
                    int ni = pi+(k-1)%2, nj = pj+(k-2)%2;
                    if(!inr(0, ni, h+2) || !inr(0, nj, w+2)) continue;
                    if(s[ni][nj] == '#') continue;
                    if(col[ni][nj] != -1) continue;
                    que.push({ni, nj});
                    col[ni][nj] = cnt;
                }
            }
            cnt++;
        }
    }

    cout << cnt-1 << endl;
    return 0;
}