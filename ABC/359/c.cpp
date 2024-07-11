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
    ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    if(tx < sx && (sx+sy)%2 == 1) sx--;
    if(sx < tx && (sx+sy)%2 == 0) sx++;
    ll ans = 0;
    ll dy = abs(sy-ty);
    ans = dy;
    if(sx+dy < tx){
        if((ty+sx+dy)%2) ans += (tx-sx-dy+1)/2;
        else ans += (tx-sx-dy)/2;
    }else if(tx < sx-dy){
        if((ty+sx-dy)%2) ans += (sx-dy-tx)/2;
        else ans += (sx-dy-tx+1)/2;
    }
    cout << ans << endl;
    
    return 0;
}