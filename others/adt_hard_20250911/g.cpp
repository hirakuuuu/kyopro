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
    queue<pair<int, int>> que;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    rep(i, 0, h){
        cin >> s[i];
        rep(j, 0, w){
            if(s[i][j] == 'E'){
                dist[i][j] = 0;
                que.push({i, j});
            }
        }
    }

    vector<string> t = s;
    string dir = "v>^<";

    while(!que.empty()){
        auto [qi, qj] = que.front(); que.pop();
        rep(k, 0, 4){
            int ni = qi+(k-1)%2, nj = qj+(k-2)%2;
            if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
            if(s[ni][nj] != '.') continue;
            if(dist[ni][nj] != -1) continue;
            dist[ni][nj] = dist[qi][qj]+1;
            que.push({ni, nj});
            t[ni][nj] = dir[k];
        }
    }

    rep(i, 0, h){
        rep(j, 0, w){
            cout << t[i][j];
        }
        cout << endl;
    }
    return 0;
}