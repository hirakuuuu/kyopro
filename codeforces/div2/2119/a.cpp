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
        ll a, b, x, y; cin >> a >> b >> x >> y;
        if(a == b){
            cout << 0 << endl;
        }else if(a%2 == 1 && (a^1) == b){
            cout << y << endl;
        }else{
            if(b < a){
                cout << -1 << endl;
            }else{
                int ans = 0;
                while(a < b){
                    if(a%2 == 0) ans += min(x, y);
                    else ans += x;
                    a++;
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}