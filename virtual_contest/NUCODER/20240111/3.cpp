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
    vector F(n, vector<vector<int>>(5, vector<int>(2)));
    vector<int> f(n);
    rep(i, 0, n){
        rep(j, 0, 5){
            rep(k, 0, 2){
                cin >> F[i][j][k];
                f[i] += F[i][j][k]*(1<<(2*j+k));
            }
        }
    }
    vector p(n, vector<ll>(10));
    rep(i, 0, n){
        rep(j, 0, 11) cin >> p[i][j];
    }
    ll ans = -9e18;
    rep(i, 1, 1<<10){
        ll tmp = 0;
        rep(j, 0, n){
            int c = popcount((unsigned)(i&f[j]));
            tmp += p[j][c];
        }
        chmax(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}