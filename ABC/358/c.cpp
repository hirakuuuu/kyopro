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
    int n, m; cin >> n >> m;
    vector<int> s(n);
    rep(i, 0, n){
        string t; cin >> t;
        rep(j, 0, m){
            if(t[j] == 'o') s[i] += (1<<j);
        }
    }

    int ans = n;
    rep(i, 0, 1<<n){
        int tmp = 0;
        rep(j, 0, n){
            if((i>>j)&1) tmp |= s[j];
        }
        if(tmp == (1<<m)-1) chmin(ans, __popcount(i));
    }
    cout << ans << endl;
    
    return 0;
}