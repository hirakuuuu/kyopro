#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

vector<vector<vector<int>>> dist(1005, vector<vector<int>>(1005, vector<int>(4, 100000007)));
vector<vector<int>> s(1005, vector<int>(1005, 1));
vector<int> dh={1, 0, -1, 0}, dw={0, 1, 0, -1};

void dijk(int r1, int c1){
    rep(i, 0, 4) dist[r1][c1][i] = 0;
    queue<pii> que;
    que.push({r1, c1});
    while(!que.empty()){
        pii q = que.front(); que.pop();
        rep(i, 0, 4){
            if(s[q.first+dh[i]][q.second+dw[i]]) continue;
            if(dist[q.first+dh[i]][q.second+dw[i]][i] > dist[q.first][q.second][i]){
                rep(j, 0, 4){
                    if(i == j) dist[q.first+dh[i]][q.second+dw[i]][j] = dist[q.first][q.second][i];
                    else dist[q.first+dh[i]][q.second+dw[i]][j] = min(dist[q.first+dh[i]][q.second+dw[i]][j], dist[q.first][q.second][i]+1);
                }
                que.push({q.first+dh[i], q.second+dw[i]});
            }
        }
    }
}


int main(){
    int h, w; cin >> h >> w;
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            char ss; cin >> ss;
            if(ss == '.') s[i][j] = 0;
        }
    }
    dijk(r1, c1);
    int ans = 100000007;
    rep(i, 0, 4) ans = min(ans, dist[r2][c2][i]);
    cout << ans << endl;
}