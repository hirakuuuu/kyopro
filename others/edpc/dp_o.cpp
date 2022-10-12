#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/dp/tasks/dp_o

/*多分bitdpな気がする*/

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n+1));
    rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];

    vector<ll> dp(1<<n);
    dp[0] = 1;
    vector<vector<ll>> cnt(n+1);
    rep(i, 0, 1<<n){
        int c = 0, j = i;
        while(j > 0){
            c += j%2;
            j /= 2;
        }
        cnt[c].push_back(i);
    }

    rep(i, 0, n){
        for(auto c: cnt[i]){
            rep(j, 0, n){
                if((c&(1<<j)) == 0 and a[i][j] == 1){
                    dp[c+(1<<j)] += dp[c];
                    dp[c+(1<<j)] %= MOD;
                }
            }
        }
    }

    cout << dp[(1<<n)-1] << endl;



    
    return 0;
}