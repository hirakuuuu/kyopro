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
// 

int main(){
    int n; cin >> n;
    vector<vector<int>> d(n+1, vector<int>(n+1));
    rep(i, 1, n+1){
        rep(j, 1, n+1){
            cin >> d[i][j];
        }
    }
    vector<vector<int>> acc(n+1, vector<int>(n+1));
    rep(i, 1, n+1){
        rep(j, 1, n+1){
            acc[i][j] = d[i][j]+acc[i-1][j]+acc[i][j-1]-acc[i-1][j-1];
        }
    }

    int q; cin >> q;
    while(q--){
        int p; cin >> p;
        int ans = 0;
        rep(w, 1, n+1){
            int h = min(n, p/w);
            rep(i, h, n+1){
                rep(j, w, n+1){
                    chmax(ans, acc[i][j]-acc[i-h][j]-acc[i][j-w]+acc[i-h][j-w]);
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}