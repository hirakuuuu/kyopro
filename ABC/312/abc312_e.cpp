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
// https://atcoder.jp/contests/abc312/tasks/abc312_e

int main(){
    int n; cin >> n;
    vector<vector<vector<int>>> belong(101, vector<vector<int>>(101, vector<int>(101)));
    rep(id, 1, n+1){
        int x1, y1, z1; cin >> x1 >> y1 >> z1;
        int x2, y2, z2; cin >> x2 >> y2 >> z2;

        rep(i, x1, x2){
            rep(j, y1, y2){
                rep(k, z1, z2){
                    belong[i][j][k] = id;
                }
            }
        }
    }

    vector<set<int>> ans(n+1);
    rep(i, 0, 101){
        rep(j, 0, 101){
            rep(k, 0, 101){
                if(belong[i][j][k] == 0) continue;
                int id = belong[i][j][k];

                if(i-1 >= 0 && belong[i-1][j][k] && belong[i-1][j][k] != id) ans[id].insert(belong[i-1][j][k]);
                if(j-1 >= 0 && belong[i][j-1][k] && belong[i][j-1][k] != id) ans[id].insert(belong[i][j-1][k]);
                if(k-1 >= 0 && belong[i][j][k-1] && belong[i][j][k-1] != id) ans[id].insert(belong[i][j][k-1]);
                if(i+1 <= 100 && belong[i+1][j][k] && belong[i+1][j][k] != id) ans[id].insert(belong[i+1][j][k]);
                if(j+1 <= 100 && belong[i][j+1][k] && belong[i][j+1][k] != id) ans[id].insert(belong[i][j+1][k]);
                if(k+1 <= 100 && belong[i][j][k+1] && belong[i][j][k+1] != id) ans[id].insert(belong[i][j][k+1]);
            }
        }
    }

    rep(i, 1, n+1){
        cout << ans[i].size() << endl;
    }
    
    return 0;
}