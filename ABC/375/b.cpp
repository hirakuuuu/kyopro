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
    long double px = 0.0, py = 0.0;
    long double ans = 0.0;
    rep(i, 0, n){
        long double qx, qy; cin >> qx >> qy;
        ans += sqrt((px-qx)*(px-qx)+(py-qy)*(py-qy));
        px = qx, py = qy;
    }
    ans += sqrt(px*px+py*py);
    cout << setprecision(20) << ans << endl;
    return 0;
}