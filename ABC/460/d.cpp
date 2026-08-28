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

vector<int> di = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> dj = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h){
        cin >> s[i];
    }

    queue<pair<int, int>> que;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    rep(i, 0, h){
        rep(j, 0, w){
            if(s[i][j] == '#'){
                bool ok = false;
                rep(k, 0, 8){
                    int ni = i+di[k], nj = j+dj[k];
                    if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
                    if(s[ni][nj] == '.') ok = true;
                }
                if(ok){
                    que.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
    }
    if(que.empty()){
        rep(i, 0, h){
            rep(j, 0, w){
                cout << '.';
            }
            cout << endl;
        }
        return 0;
    }
    while(!que.empty()){
        auto [pi, pj] = que.front(); que.pop();
        rep(k, 0, 8){
            int ni = pi+di[k], nj = pj+dj[k];
            if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
            if(dist[ni][nj] != -1) continue;
            dist[ni][nj] = dist[pi][pj]+1;
            que.push({ni, nj});
        }
    }

    rep(i, 0, h){
        rep(j, 0, w){
            if(dist[i][j]%2 == 0) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }


    
    return 0;
}