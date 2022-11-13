#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/agc009/tasks/agc009_b

int main(){
    int n; cin >> n;
    vector<int> a(n+1), cnt(n+1);
    vector<vector<int>> ch(n+1);
    rep(i, 2, n+1){
        cin >> a[i];
        cnt[a[i]]++;
    }

    rep(i, 1, n+1){
        ch[a[i]].push_back(i);
    }

    queue<int> que;
    rep(i, 1, n+1){
        if(cnt[i] == 0) que.push(i);
    }

    vector<int> dp(n+1, 1e9);
    while(!que.empty()){
        int q = que.front(); que.pop();
        vector<int> s;
        for(auto c: ch[q]){
            s.push_back(dp[c]);
        }
        sort(s.begin(), s.end(), greater<int>());
        int max_dp = 0;
        rep(i, 0, s.size()){
            max_dp = max(max_dp, s[i]+i+1);
        }
        dp[q] = max_dp;
        cnt[a[q]]--;
        if(cnt[a[q]] == 0) que.push(a[q]);
    }

    cout << dp[1] << endl;
    
    return 0;
}