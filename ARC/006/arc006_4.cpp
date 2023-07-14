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
// https://atcoder.jp/contests/arc006/tasks/arc006_4

vector<int> di = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> dj = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
    int h, w; cin >> h >> w;
    vector<int> cnt = {12, 16, 11};
    vector<int> ans(3);
    vector<vector<int>> d(h+2, vector<int>(w+2));
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            char c; cin >> c;
            d[i][j] = (c == 'o' ? 1 : 0);
        }
    }

    vector<vector<bool>> seen(h+2, vector<bool>(w+2));
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            if(d[i][j] == 0 || seen[i][j]) continue;

            queue<pair<int, int>> que;
            que.push({i, j});
            seen[i][j] = true;
            int sum_d = 1;
            int min_i = 1e9, min_j = 1e9;
            int max_i = -1, max_j = -1;
            while(!que.empty()){
                auto [pi, pj] = que.front(); que.pop();
                chmin(min_i, pi);
                chmin(min_j, pj);
                chmax(max_i, pi);
                chmax(max_j, pj);
                rep(k, 0, 8){
                    int ni = pi+di[k], nj = pj+dj[k];
                    if(d[ni][nj] == 0 || seen[ni][nj]) continue;
                    sum_d++;
                    que.push({ni, nj});
                    seen[ni][nj] = true;
                }
            }
            sum_d /= (max_i-min_i+1)*(max_j-min_j+1)/25;
            rep(k, 0, 3){
                if(sum_d == cnt[k]) ans[k]++;
            }
        }
    }

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;


    
    return 0;
}