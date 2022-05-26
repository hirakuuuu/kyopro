#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc118/tasks/abc118_d

int change_num(int a){
    vector<int> num = {0,2,5,5,4,5,6,3,7,6};
    return num[a];
}

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m);
    rep(i, 0, m) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    sort(a.begin(), a.end(), [](const int a1, const int a2){
        return change_num(a1) < change_num(a2);
    });
    // rep(i, 0, m){
    //     cout << a[i] << endl;
    // }
    vector<int> ans(10);
    vector<vector<int>> dp(n+1, vector<int>(10, 0));
    rep(i, 1, n+1){
        dp[i][0] = -1;
    }

    rep(i, 0, n+1){
        for(auto aa: a){
            if(i >= change_num(aa)){
                if(dp[i-change_num(aa)][0] == -1) continue;
                vector<int> dp_ = dp[i-change_num(aa)];
                dp_[0]++;
                dp_[10-aa]++;
                dp[i] = max(dp[i], dp_);
            }
        }
    }


    rep(i, 1, 10){
        rep(j, 0, dp[n][i]){
            cout << 10-i;
        }
    }
    cout << endl;
    return 0;
}