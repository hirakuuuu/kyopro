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
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, n){
            a[i][j] = s[j]-'0';
        }
    }
    vector<int> di = {n-1, n-1, n-1 , 0, 0, 1, 1, 1};
    vector<int> dj = {n-1, 0, 1 , n-1, 1, n-1, 0, 1};
    ll ans = 0;
    rep(i, 0, n){
        rep(j, 0, n){
            rep(k, 0, 8){
                ll tmp = 0;
                rep(l, 0, n){
                    tmp = tmp*10+a[(i+l*di[k])%n][(j+l*dj[k])%n];
                }
                chmax(ans, tmp);
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}