#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc276/tasks/abc276_e

int h, w;
int check(int i, int j){
    return (0 <= i and i < h and 0 <= j and j < w);
}

int main(){
    cin >> h >> w;
    vector<string> c(h);
    int sh, sw;
    rep(i, 0, h){
        cin >> c[i];
        rep(j, 0, w){
            if(c[i][j] == 'S'){
                sh = i;
                sw = j;
            }
        }
    }

    vector<pii> s;
    rep(i, 0, 4){
        int nh = sh+(i-1)%2, nw = sw+(i-2)%2;
        if(check(nh, nw) and c[nh][nw] == '.'){
            s.push_back({nh, nw});
        }
    }

    bool ans = false;
    rep(i, 0, s.size()){
        rep(j, i+1, s.size()){
            pii start = s[i], goal = s[j];
            vector<vector<bool>> seen(h, vector<bool>(w));
            queue<pii> que;
            que.push(start);
            seen[start.first][start.second] = true;
            while(!que.empty()){
                pii q = que.front(); que.pop();
                rep(k, 0, 4){
                    int nh = q.first+(k-1)%2, nw = q.second+(k-2)%2;
                    if(check(nh, nw) and c[nh][nw] == '.' and !seen[nh][nw]){
                        seen[nh][nw] = true;
                        que.push({nh, nw});
                    }
                }
            }
            ans |= seen[goal.first][goal.second];
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}