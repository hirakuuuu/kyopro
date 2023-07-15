#include <bits/stdc++.h>
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main(){
    int r, c; cin >> r >> c;
    int sy, sx; cin >> sy >> sx;
    sy--;
    sx--;
    int gy, gx; cin >> gy >> gx; 
    gy--;
    gx--;

    vector<string> C(r);
    for(int i = 0; i < r; i++) cin >> C[i];

    vector<vector<int>> dist(r, vector<int>(c, 1001001001));
    dist[sy][sx] = 0;
    queue<pair<int, int>> que;
    que.push({sy, sx});
    while(!que.empty()){
        auto [py, px] = que.front(); que.pop();
        for(int i = 0; i < 4; i++){
            int ny = py+dy[i], nx = px+dx[i];
            if(C[ny][nx] == '#' || dist[ny][nx] != 1001001001) continue;
            que.push({ny, nx});
            dist[ny][nx] = dist[py][px]+1;
        }
    }

    cout << dist[gy][gx] << endl;

    return 0;
}