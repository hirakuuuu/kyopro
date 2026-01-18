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
    int t; cin >> t;
    while(t--){
        ll a, b, c; cin >> a >> b >> c;
        ll ok = 0, ng = INF;
        while(ng-ok > 1){
            ll mid = (ok+ng)/2;
            if(a >= mid && c >= mid && (a+b+c-2*mid) >= mid){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        cout << ok << endl;
    }
    
    return 0;
}