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
// https://atcoder.jp/contests/abc260/tasks/abc260_f

int main(){
    int s, t, m; cin >> s >> t >> m;
    vector<vector<int>> g(s+1);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    vector<vector<int>> connect(t+1, vector<int>(t+1, -1));
    rep(i, 1, s+1){
        for(auto x: g[i]){
            for(auto y: g[i]){
                if(x == y || x > y) continue;
                if(connect[x-s][y-s] == -1) connect[x-s][y-s] = i;
                else{
                    cout << connect[x-s][y-s] << ' ' << x << ' ' << i << ' ' << y << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    
    return 0;
}