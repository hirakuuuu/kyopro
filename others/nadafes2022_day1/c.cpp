#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_c

int main(){
    int h, w, k; cin >> h >> w >> k;
    vector<vector<char>> a(h+2, vector<char>(w+2, '#'));
    queue<pii> magma;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            cin >> a[i][j];
            if(a[i][j] == '@') magma.push({i, j});
        }
    }

    vector<vector<int>> dist(h+2, vector<int>(w+2, -1));
    dist[1][1] = 0;
    queue<pii> que;
    que.push({1, 1});
    int i = 1;
    while(!que.empty()){
        // マグマが浸食するときの処理（計算量そんなにかからないはず）
        if(i%k == 0){
            queue<pii> cp_magma;
            while(!magma.empty()){
                pii m = magma.front(); magma.pop();
                rep(j, 0, 4){
                    int nh = m.first+(j-1)%2, nw = m.second+(j-2)%2;
                    if(a[nh][nw] == '.'){
                        a[nh][nw] = '@';
                        cp_magma.push({nh, nw});
                    }
                }
            }
            magma = cp_magma;
            // cout << endl;
            // rep(j, 1, h+1){
            //     rep(l, 1, w+1) cout << a[j][l];
            //     cout << endl;
            // }

        }

        // BFS
        queue<pii> cp_que;
        while(!que.empty()){
            pii q = que.front(); que.pop();
            rep(j, 0, 4){
                int nh = q.first+(j-1)%2, nw = q.second+(j-2)%2;
                if(dist[nh][nw] < 0 and a[nh][nw] == '.'){
                    dist[nh][nw] = i;
                    cp_que.push({nh, nw});
                }
            }
        }
        que = cp_que;
        i++;
        // if(a[h][w] == '@' or dist[h][w] >= 0) break;

    }

    if(dist[h][w] < 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    
    return 0;
}