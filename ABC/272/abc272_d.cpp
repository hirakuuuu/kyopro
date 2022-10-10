#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc272/tasks/abc272_d

int main(){
    int n, m; cin >> n >> m;

    map<int, bool> is_square;
    rep(i, 0, 1001) is_square[i*i] = true;

    vector<pii> can_move;

    rep(k, 0, n+1){
        if(is_square[m-k*k]){
            can_move.push_back({k, sqrt(m-k*k)});
        }
    }
    vector<vector<int>> dist(n+1, vector<int>(n+1, -1));
    queue<pii> que;
    que.push({1, 1});
    dist[1][1] = 0;

    vector<pii> d = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    while(!que.empty()){
        pii q = que.front(); que.pop();
        int i = q.first, j = q.second;
        for(auto cm: can_move){
            rep(l, 0, 4){
                int nx = i+d[l].first*cm.first;
                int ny = j+d[l].second*cm.second;
                if(1 <= nx and nx <= n and 1 <= ny and ny <= n and dist[nx][ny] == -1){
                    dist[nx][ny] = dist[i][j]+1;
                    que.push({nx, ny});
                }
            }
        }
    }

    rep(i, 1, n+1){
        rep(j, 1, n+1){
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}