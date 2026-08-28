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
    vector<vector<int>> a(3, vector<int>(6));
    vector<vector<int>> p(3, vector<int>(6));
    rep(i, 0, 3){
        rep(j, 0, 6){
            cin >> a[i][j];
            a[i][j]--;
            p[i][a[i][j]]++;
        }
    }

    long double ans = 0.0;
    ans += (long double)p[0][3]*p[1][4]*p[2][5]/216.0;
    ans += (long double)p[0][3]*p[1][5]*p[2][4]/216.0;
    ans += (long double)p[0][4]*p[1][3]*p[2][5]/216.0;
    ans += (long double)p[0][4]*p[1][5]*p[2][3]/216.0;
    ans += (long double)p[0][5]*p[1][3]*p[2][4]/216.0;
    ans += (long double)p[0][5]*p[1][4]*p[2][3]/216.0;
    cout << setprecision(20) << ans << endl;
    return 0;
}