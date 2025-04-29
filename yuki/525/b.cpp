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

int gcd(int a, int b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

int main(){
    vector<vector<int>> a(2, vector<int>(2));
    rep(i, 0, 2) rep(j, 0, 2){
        cin >> a[i][j];
    }

    ll g = abs(a[0][0]);
    rep(i, 0, 2) rep(j, 0, 2){
        if(a[i][j] == 0) continue;
        g = gcd(g, abs(a[i][j]));
    }
    ll dat = abs((ll)a[0][0]*a[1][1]-(ll)a[0][1]*a[1][0]);
    if(g == 0) cout << 0 << ' ' << 0 << endl;
    else if(dat == 0) cout << g << ' ' << 0 << endl;
    else cout << g << ' ' << dat/g << endl;
    return 0;
}