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
    int a, b; cin >> a >> b;
    if((b&a) != a){
        cout << 0 << endl;
        return 0;
    }

    int ans = 1;
    rep(i, 0, 30){
        if((b>>i)&1){
            if((a>>i)&1) ans *= 2;
        }
    }
    cout << ans << endl;
    return 0;
}