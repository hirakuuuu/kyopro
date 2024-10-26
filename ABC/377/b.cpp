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
    int n = 8;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    int ans = 0;
    rep(i, 0, n) rep(j, 0, n){
        if(s[i][j] == '#') continue;
        // マス (i, j) に置いたときに、他の駒にとられるかどうか
        bool ng = false;
        rep(k, 0, n){
            if(s[i][k] == '#') ng = true;
            if(s[k][j] == '#') ng = true;
        }
        if(!ng) ans++;
    }
    cout << ans << endl;

    return 0;
}