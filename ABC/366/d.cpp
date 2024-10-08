#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<vector<vector<int>>> a(n, vector<vector<int>>(n, vector<int>(n)));
    rep(i, 0, n){
        rep(j, 0, n){
            rep(k, 0, n){
                cin >> a[i][j][k];
            }
        }
    }
    vector<vector<vector<int>>> acc(n+1, vector<vector<int>>(n+1, vector<int>(n+1)));
    rep(i, 1, n+1){
        rep(j, 1, n+1){
            rep(k, 1, n+1){
                acc[i][j][k] = acc[i-1][j][k]+acc[i][j-1][k]+acc[i][j][k-1]
                              -acc[i][j-1][k-1]-acc[i-1][j][k-1]-acc[i-1][j-1][k]
                              +acc[i-1][j-1][k-1]
                              +a[i-1][j-1][k-1];
            }
        }
    }

    int q; cin >> q;
    while(q--){
        int lx, rx, ly, ry, lz, rz; cin >> lx >> rx >> ly >> ry >> lz >> rz;
        lx--, ly--, lz--;
        int ans = acc[rx][ry][rz]
                  -acc[lx][ry][rz]-acc[rx][ly][rz]-acc[rx][ry][lz]
                  +acc[lx][ly][rz]+acc[lx][ry][lz]+acc[rx][ly][lz]
                  -acc[lx][ly][lz];
        cout << ans << endl;
    }
    return 0;
}