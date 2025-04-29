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
    ll r; cin >> r;
    ll ans = r*2-1;
    for(ll x = 1; x < r; x++){
        // (x, ?) で円に入る個数を考える
        ll ok = 1, ng = 2e6;
        while(ng-ok > 1){
            ll mid = (ok+ng)/2;
            if((2*x+1)*(2*x+1)+(2*mid-1)*(2*mid-1) <= 4*r*r) ok = mid;
            else ng = mid;
        }
        // cout << x << ' ' << ok << endl;
        ans += (ok*2-1)*2;
    }
    cout << ans << endl;
    
    return 0;
}