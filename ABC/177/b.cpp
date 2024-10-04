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
    string s, t; cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    int ans = IINF;
    rep(i, 0, n-m+1){
        int cnt = 0;
        rep(j, i, i+m){
            if(s[j] != t[j-i]) cnt++;
        }
        chmin(ans, cnt);
    }
    cout << ans << endl;
    
    return 0;
}