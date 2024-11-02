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
    int h, w, k; cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    auto f = [&](auto self, int x, int y, int d) -> ll {
        if(d == k) return 1;
        ll res = 0;
        rep(i, 0, 4){
            int nx = x+(i-1)%2, ny = y+(i-2)%2;
            if(!inr(0, nx, h) || !inr(0, ny, w)) continue;
            if(s[nx][ny] == '#') continue;
            s[x][y] = '#';
            res += self(self, nx, ny, d+1);
            s[x][y] = '.';
        }
        return res;
    };

    ll ans = 0;
    rep(i, 0, h) rep(j, 0, w){
        if(s[i][j] == '#') continue;
        ans += f(f, i, j, 0);
    }
    cout << ans << endl;
    
    return 0;
}