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
// https://atcoder.jp/contests/abc197/tasks/abc197_f

vector<vector<bool>> edge(1005, vector<bool>(1005));
vector<vector<bool>> seen(1005, vector<bool>(1005));
vector<vector<vector<int>>> g(26, vector<vector<int>>(1005));
vector<vector<vector<pair<int, int>>>> nxt(1005, vector<vector<pair<int, int>>>(1005));


int main(){
    int n, m; cin >> n >> m;
    rep(i, 0, m){
        int a, b;
        char c; cin >> a >> b >> c;
        a--, b--;
        g[c-'a'][a].push_back(b);
        g[c-'a'][b].push_back(a);
        edge[a][b] = edge[b][a] = true;
    }

    rep(i, 0, n){
        rep(j, i+1, n){
            rep(k, 0, 26){
                for(auto gi: g[k][i]){
                    for(auto gj: g[k][j]){
                        nxt[i][j].push_back({min(gi, gj), max(gi, gj)});
                    }
                }
            }
        }
    }

    queue<pair<int, int>> que;
    que.push({0, n-1});
    seen[0][n-1] = true;
    vector<vector<int>> len(n, vector<int>(n, -1));
    len[0][n-1] = 0;
    int ans = 1001001001;
    while(!que.empty()){
        auto [l, r] = que.front(); que.pop();
        for(auto [nl, nr]: nxt[l][r]){
            if(nl == nr){
                len[nl][nr] = len[l][r]+2;
                chmin(ans, len[nl][nr]);
            }else if(l == nl && r == nr && edge[nl][nr]){
                len[nl][nr] = len[l][r]+1;
                chmin(ans, len[nl][nr]);
            }else{
                if(seen[nl][nr]) continue;
                seen[nl][nr] = true;
                len[nl][nr] = len[l][r]+2;
                que.push({nl, nr});
            }
        }
    }


    if(ans == 1001001001) cout << -1 << endl;
    else cout << ans << endl;



    return 0;
}