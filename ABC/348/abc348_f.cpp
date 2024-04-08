#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<bitset<2005>> b(1005);
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> a[i][j];
        }
    }
    rep(i, 0, n){
        b[a[i][0]].set(i, 1);
    }
    vector<bitset<2005>> dp(n);
    rep(i, 0, m){
        rep(j, 0, n){
            dp[j] ^= b[a[j][i]];
        }
        if(i == m-1) break;
        rep(j, 0, n){
            assert(b[a[j][i]][j] == 1);
            b[a[j][i]].flip(j);
            b[a[j][i+1]].flip(j);
        }
    }
    int ans = 0;
    rep(i, 0, n){
        ans += dp[i].count();
    }
    if(m%2 == 1) ans -= n;
    cout << ans/2 << endl;


    
    return 0;
}