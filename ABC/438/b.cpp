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
    vector<int> s(n), t(m);
    rep(i, 0, n){
        char c; cin >> c;
        s[i] = c-'0';
    }
    rep(i, 0, m){
        char c; cin >> c;
        t[i] = c-'0';
    }

    int ans = IINF;
    rep(i, 0, n-m+1){
        int cnt = 0;
        rep(j, 0, m){
            if(s[i+j] >= t[j]) cnt += s[i+j]-t[j];
            else cnt += (10-t[j])+s[i+j];
        }
        chmin(ans, cnt);
    }
    cout << ans << endl;
    
    return 0;
}