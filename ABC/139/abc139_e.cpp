#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc139/tasks/abc139_e

vector<vector<int>> g(500005);
vector<vector<int>> g_re(500005);
vector<int> cnt_indegree(500005);
vector<int> topological;

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n-1));
    map<pii, int> id;
    int cnt = 0;
    rep(i, 0, n){
        rep(j, i+1, n){
            id[{i, j}] = cnt;
            cnt++;
        }
    }

    rep(i, 0, n){
        rep(j, 0, n-1){
            pii card;
            card.first = i;
            cin >> card.second; card.second--;
            if(card.first > card.second) swap(card.first, card.second);
            a[i][j] = id[card];
        }
    }

    rep(i, 0, n){
        rep(j, 0, n-2){
            g[a[i][j]].push_back(a[i][j+1]);
            g_re[a[i][j+1]].push_back(a[i][j]);
            cnt_indegree[a[i][j+1]]++;
        }
    }

    int ans = -1;

    // トポロジカルソート
    cnt = 0;
    queue<int> que;
    rep(i, 0, n*(n-1)/2){
        if(cnt_indegree[i] == 0){
            que.push(i);
            cnt++;
        }
    }
    while(!que.empty()){
        int q = que.front(); que.pop();
        topological.push_back(q);
        for(auto nq: g[q]){
            cnt_indegree[nq]--;
            if(cnt_indegree[nq] == 0){
                que.push(nq);
                cnt++;
            }
        }
    }


    if(cnt == n*(n-1)/2){
        vector<int> dp(n*(n-1)/2);
        for(auto node: topological){
            for(auto nn: g_re[node]){
                dp[node] = max(dp[node], dp[nn]);
            }
            dp[node]++;
            ans = max(ans, dp[node]);
        }
    }

    cout << ans << endl;
    
    return 0;
}