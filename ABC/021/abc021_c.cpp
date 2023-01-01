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
// https://atcoder.jp/contests/abc021/tasks/abc021_c

vector<vector<int>> g(105);
vector<int> dist(105, -1), ans(105);

int main(){
    int n, a, b, m; cin >> n >> a >> b >> m;
    rep(i, 0, m){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dist[a] = 0;
    ans[a] = 1;
    int tmp = 0;

    while(dist[b] == -1){
        rep(i, 1, n+1){
            if(dist[i] == tmp){
                for(const auto &gg: g[i]){
                    if(dist[gg] == -1){
                        dist[gg] = tmp+1;
                    }
                    if(dist[gg] == dist[i]+1) ans[gg] += ans[i];
                    ans[gg] %= MOD;
                }
            }
        }
        tmp++;
    }

    // rep(i, 1, n+1){
    //     cout << ans[i] << endl;
    // }
    cout << ans[b] << endl;


    
    return 0;
}