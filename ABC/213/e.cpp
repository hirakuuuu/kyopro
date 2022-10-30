#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc213/tasks/abc213_e

int main(){
    int h, w; cin >> h >> w;
    vector<vector<char>> field(h, vector<char>(w));
    rep(i, 0, h){
        rep(j, 0, w) cin >> field[i][j];
    }

    vector<vector<int>> dp(h, vector<int>(w, 10000000));
    vector<int> dh ={-1, 0, 1, 0, 1, 1, -1, -1}, dw = {0, -1, 0, 1, 1, -1, -1, 1};
    dp[0][0] = 0;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> que;
    que.push({0, 0, 0});
    while(!que.empty()){
        vector<int> q = que.top(); que.pop();
        rep(i, 0, 4){
            int nh = q[1]+dh[i], nw = q[2]+dw[i];
            if(0 <= nh and 0 <= nw and nh < h and nw < w){
                if(field[nh][nw] == '.' and dp[nh][nw] > dp[q[1]][q[2]]){
                    dp[nh][nw] = dp[q[1]][q[2]];
                    que.push({dp[nh][nw], nh, nw});
                }else if(field[nh][nw] == '#'){
                    if(dp[nh][nw] > dp[q[1]][q[2]]+1){
                        dp[nh][nw] = dp[q[1]][q[2]] + 1;
                        que.push({dp[nh][nw], nh, nw});
                    }
                    if(dp[nh][nw] == dp[q[1]][q[2]]+1){
                        rep(j, 0, 8){
                            int nnh = nh+dh[j], nnw = nw+dw[j];
                            if(0 <= nnh and 0 <= nnw and nnh < h and nnw < w){
                                if(dp[nnh][nnw] > dp[nh][nw]){
                                    dp[nnh][nnw] = dp[nh][nw];
                                    que.push({dp[nnh][nnw], nnh, nnw});
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << dp[h-1][w-1] << endl;
    return 0;
}