#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc317/tasks/abc317_e

int main(){
    int h, w; cin >> h >> w; 
    vector<vector<char>> a(h+2, vector<char>(w+2, '#'));
    int sh, sw, gh, gw;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            cin >> a[i][j];
            if(a[i][j] == 'S') sh = i, sw = j;
            if(a[i][j] == 'G') gh = i, gw = j;
        }
    }

    vector<vector<char>> b = a;
    string dir = "^<v>";
    vector<int> dh = {-1, 0, 1, 0};
    vector<int> dw = {0, -1, 0, 1};
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            rep(k, 0, 4){
                if(a[i][j] == dir[k]){
                    int cnt = 1;
                    while(a[i+cnt*dh[k]][j+cnt*dw[k]] == '.'){
                        b[i+cnt*dh[k]][j+cnt*dw[k]] = '#';
                        cnt++;
                    }
                    b[i][j] = '#';
                }
            }
        }
    }




    queue<pair<int, int>> que;
    vector<vector<int>> seen(h+2, vector<int>(w+2, -1));
    seen[sh][sw] = 0;
    que.push({sh, sw});
    while(!que.empty()){
        auto [ch, cw] = que.front(); que.pop();
        rep(i, 0, 4){
            int nh = ch+dh[i], nw = cw+dw[i];
            if(seen[nh][nw] != -1) continue;
            if(b[nh][nw] == '.' || b[nh][nw] == 'G'){
                seen[nh][nw] = seen[ch][cw] + 1;
                que.push({nh, nw});
            }
        }
    }


    cout << seen[gh][gw] << endl;
    
    return 0;
}