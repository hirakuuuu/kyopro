#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc154/tasks/abc154_e

ll dp[105][2][5];

int main(){
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();

    dp[0][0][0] = 1;
    rep(i, 0, n){
        rep(j, 0, 2){
            rep(cnt, 0, k+1){
                int c = s[i]-'0';
                rep(nxt, 0, 10){
                    if(c < nxt and j == 0) continue;
                    int j2 = j;
                    if(nxt < c) j2 = 1;
                    int cnt2 = cnt;
                    if(nxt != 0) cnt2++;

                    dp[i+1][j2][cnt2] += dp[i][j][cnt];
                }
            }
        }
    }

    cout << dp[n][0][k]+dp[n][1][k] << endl;

    return 0;
}