#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

vector<vector<int>> g(100005);
vector<ll> dp(100005, 1);
int n;

void dfs(int pos, int pre){
    for(auto npos: g[pos]){
        if(npos == pre) continue;
        dfs(npos, pos);
        dp[pos] += dp[npos];
    }
}


ll solve(){
    ll ans = 0;
    queue<pii> que;
    que.push(make_pair(0, -1));
    while(!que.empty()){
        pii q = que.front(); que.pop();
        for(auto nq: g[q.first]){
            if(nq == q.second) continue;
            ans += dp[nq]*(n-dp[nq]);
            que.push(make_pair(nq, q.first));
        }
    }
    return ans;
}


int main(){
    cin >> n;
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    dfs(0, -1);
    cout << solve() << endl;
}