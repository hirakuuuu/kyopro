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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    vector<vector<int>> acc(n, vector<int>(n+1));
    rep(i, 0, n){
        rep(j, 1, n+1){
            acc[i][j] = acc[i][j-1];
            if(s[i][j-1] == 'O') acc[i][j]++;
        }
    }   

    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y; x--, y--;
        int ans = 0;
        rep(i, 0, x+1){
            int l = -2*i-2*m+2*x+y;
            // cout << i << ' ' << l <<  ' ' << y << endl;
            if(l >= y) continue;
            if(l < 0) l = 0;
            else l++;
            ans += max(0, acc[i][y+1]-acc[i][l]);
        }
        cout << ans << endl;
    }
    return 0;
}