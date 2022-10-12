#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc184/tasks/abc184_e

int main(){
    int h, w; cin >> h >> w;
    vector<string> a(h+2);
    rep(i, 0, w+2){
        a[0] += '#';
        a[h+1] += '#';
    }
    rep(i, 1, h+1){
        cin >> a[i];
        a[i] = '#'+a[i]+'#';
    }

    int sh = 0, sw = 0, gh = 0, gw = 0;
    vector<vector<pii>> tele(26);
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            if(a[i][j] == 'S') sh = i, sw = j;
            if(a[i][j] == 'G') gh = i, gw = j;
            if('a' <= a[i][j] and a[i][j] <= 'z') tele[a[i][j]-'a'].push_back({i, j});
        }
    }

    vector<vector<int>> dist(h+1, vector<int>(w+1, -1));
    vector<bool> f(26);
    dist[sh][sw] = 0;
    queue<pii> que;
    que.push({sh, sw});

    while(!que.empty()){
        pii q = que.front(); que.pop();
        int x = q.first, y = q.second;
        rep(i, 0, 4){
            int nx = x+(i-1)%2, ny = y+(i-2)%2;
            if(a[nx][ny] == '#') continue;
            if(dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[x][y]+1;
            que.push({nx, ny});
        }

        if('a' <= a[x][y] and a[x][y] <= 'z' and !f[a[x][y]-'a']){
            int num = a[x][y]-'a';
            f[num] = true;
            for(auto t: tele[num]){
                if(dist[t.first][t.second] >= 0) continue;
                dist[t.first][t.second] = dist[x][y]+1;
                que.push(t);
            }
        }
    }

    cout << dist[gh][gw] << endl;


    
    return 0;
}