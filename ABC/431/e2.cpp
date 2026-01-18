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
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    map<char, int> d;
    d['A'] = 0;
    d['B'] = 1;
    d['C'] = 3;
    int t; cin >> t;
    while(t--){
        int h, w; cin >> h >> w;
        vector<string> s(h);
        rep(i, 0, h){
            cin >> s[i];
        }


        vector<vector<vector<int>>> dp(h, vector<vector<int>>(w, vector<int>(4, IINF)));
        deque<tuple<int, int, int, int>> dq;
        dq.push_back({0, 0, -1, 3});
        while(!dq.empty()){
            auto [c, px, py, dir] = dq.front(); dq.pop_front();
            int nx = px+dx[dir], ny = py+dy[dir];
            if(!inr(0, nx, h) || !inr(0, ny, w)) continue;

            rep(ndir, 0, 4){
                if((dir^ndir) == 2) continue;
                if((dir^ndir) == d[s[nx][ny]]){
                    if(dp[nx][ny][ndir] <= c) continue;
                    dp[nx][ny][ndir] = c;
                    dq.push_front({c, nx, ny, ndir});
                }else{
                    if(dp[nx][ny][ndir] <= c+1) continue;
                    dp[nx][ny][ndir] = c+1;
                    dq.push_back({c+1, nx, ny, ndir});
                }
            }
        }
        cout << dp[h-1][w-1][3] << endl;
    }
    
    return 0;
}