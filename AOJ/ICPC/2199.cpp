#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://onlinejudge.u-aizu.ac.jp/problems/2199

int main(){
    while(true){
        int n, m; cin >> n >> m;
        if(n == 0 and m == 0) break;
        vector<int> c(m), x(n);
        rep(i, 0, m) cin >> c[i];
        rep(i, 0, n) cin >> x[i];

        int y = 128;
        vector<pii> dp(m), dp_(m);
        rep(i, 0, m){
            if(128+c[i] < 0) dp[i] = {(x[0])*(x[0]), 0};
            else if(128+c[i] > 255) dp[i]= {(x[0]-255)*(x[0]-255), 255};
            else dp[i] = {(x[0]-(128+c[i]))*(x[0]-(128+c[i])), 128+c[i]};
        }

        rep(i, 1, n){
            dp_ = dp;
            rep(j, 0, m){
                dp[j] = {(1<<30), 0};
                rep(k, 0, m){
                    if(dp_[k].second+c[j] < 0) dp[j] = min(dp[j], {dp_[k].first+(x[i])*(x[i]), 0});
                    else if(dp[i].second > 255) dp[j] = min(dp[j], {dp_[k].first+(x[i]-255)*(x[i]-255), 255});
                    else dp[j] = min(dp[j], {dp_[k].first+(x[i]-(dp_[k].second+c[j]))*(x[i]-(dp_[k].second+c[j])), dp_[k].second+c[j]});
                }
            }
        }
        pii ans = {1<<30, 0};

        rep(i, 0, m){
            ans = min(dp[i], ans);
        }
        cout << ans.first << endl;
    }
    
    return 0;
}