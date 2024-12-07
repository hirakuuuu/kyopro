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
    int h, w, d; cin >> h >> w >> d;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    int ans = 0;
    rep(i1, 0, h) rep(j1, 0, w){
        if(s[i1][j1] == '#') continue;
        rep(i2, 0, h) rep(j2, 0, w){
            if(s[i2][j2] == '#') continue;
            int cnt = 0;
            rep(i, 0, h) rep(j, 0, w){
                if(s[i][j] == '#') continue;
                if((abs(i1-i)+abs(j1-j) <= d) || (abs(i2-i)+abs(j2-j) <= d)) cnt++;
            }
            chmax(ans, cnt);
        }
    }
    cout << ans << endl;
    
    return 0;
}