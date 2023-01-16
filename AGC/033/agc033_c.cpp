#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/agc033/tasks/agc033_c

vector<vector<int>> g(200005);
vector<int> dist(200005);
void dfs(int pos, int pre){
    for(const auto &npos: g[pos]){
        if(npos == pre) continue;
        dist[npos] = dist[pos]+1;
        dfs(npos, pos);
    }
}

int main(){
    int n; cin >> n;
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dist[1] = 0;
    dfs(1, 0);
    int ml = 0, new_start = 0;
    rep(i, 1, n+1){
        if(ml < dist[i]){
            ml = dist[i];
            new_start = i;
        }
    }

    dist[new_start] = 0;
    dfs(new_start, 0);
    int ans = 0;
    rep(i, 1, n+1){
        chmax(ans, dist[i]);
    }

    if(ans%3 == 1) cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}