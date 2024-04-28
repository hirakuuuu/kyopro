#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, t; cin >> n >> t;
    vector<int> a(n+1), b(n+1);
    rep(i, 1, n+1) cin >> a[i] >> b[i];
    vector<vector<int>> ldp(n+1, vector<int>(t));
    vector<vector<int>> rdp(n+1, vector<int>(t));
    rep(i, 1, n+1){
        rep(j, 0, t){
            chmax(ldp[i][j], ldp[i-1][j]);
            if(j+a[i] < t) chmax(ldp[i][j+a[i]], ldp[i-1][j]+b[i]);
        }
    }
    rrep(i, n, 1){
        rep(j, 0, t){
            chmax(rdp[i-1][j], rdp[i][j]);
            if(j+a[i] < t) chmax(rdp[i-1][j+a[i]], rdp[i][j]+b[i]);
        }
    }
    int ans = 0;
    rep(i, 1, n+1){
        rep(j, 0, t){
            chmax(ans, ldp[i-1][j]+rdp[i][t-1-j]+b[i]);
        }
    }
    cout << ans << endl;
    
    return 0;
}