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
    vector<vector<char>> a(h+2, vector<char>(w+2, '#'));
    vector<vector<int>> d(h+2, vector<int>(w+2, -1));
    vector<bool> f(26, true);
    vector<vector<pii>> tele(26);
    int sh = 1, sw = 1, gh = 1, gw = 1;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            cin >> a[i][j];
            if(a[i][j] == 'S') sh = i, sw = j;
            else if(a[i][j] == 'G') gh = i, gw = j;
            else if(0 <= a[i][j]-'a' and a[i][j]-'a' < 26) tele[a[i][j]-'a'].push_back({i, j});
        }
    }

    queue<pii> que;
    que.push({sh, sw});
    d[sh][sw] = 0;
    while(!que.empty()){
        pii q = que.front(); que.pop();
        rep(i, 0, 4){
            int nh = q.first-(i-1)%2, nw = q.second-(i-2)%2;
            if(a[nh][nw] == '#') continue;
            if(d[nh][nw] != -1) continue;
            d[nh][nw] = d[q.first][q.second] + 1;
            que.push({nh, nw});
        }
        if(0 <= a[q.first][q.second]-'a' and a[q.first][q.second]-'a' < 26 and f[a[q.first][q.second]-'a']){
            f[a[q.first][q.second]-'a'] = false;
            for(auto t: tele[a[q.first][q.second]-'a']){
                if(d[t.first][t.second] != -1) continue;
                d[t.first][t.second] = d[q.first][q.second]+1;
                que.push(t);
            }
        }
    }

    deque deq({sh, sw});

    cout << d[gh][gw] << endl;
    return 0;
}