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
    int n; cin >> n;
    string s; cin >> s;
    bool ok = n%2;
    rep(i, 0, n/2) if(s[i] != '1') ok = false;
    if(s[n/2] != '/') ok = false;
    rep(i, n/2+1, n) if(s[i] != '2') ok = false;

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}