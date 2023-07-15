#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
  int r, c, sx, sy, gx, gy; cin >> r >> c >> sx >> sy >> gx >> gy;
  vector<vector<char>> f(r+2, vector<char>(c+2));
  rep(i, r+2){
    rep(j, c+2){
      if(i == 0 or i == r+1 or j == 0 or j == c+1) f[i][j] = '#';
      else cin >> f[i][j];
    }
  }
  vector<vector<int>> ans(r+2, vector<int>(c+2, -1));
  queue<pair<int, int>> que;
  que.push(make_pair(sx, sy));
  ans[sx][sy] = 0;
  vector<int> dx={1, 0, -1, 0};
  vector<int> dy={0, 1, 0, -1};
  while(!que.empty()){
    pair<int, int> q = que.front(); que.pop();
    rep(i, 4){
      if(f[q.first+dx[i]][q.second+dy[i]] == '#') continue;
      if(ans[q.first+dx[i]][q.second+dy[i]] >= 0) continue;
      ans[q.first+dx[i]][q.second+dy[i]] = ans[q.first][q.second]+1;
      que.push(make_pair(q.first+dx[i], q.second+dy[i]));
    }
  }
  cout << ans[gx][gy] << endl;
}