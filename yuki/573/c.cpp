#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n; cin >> n;

    
    /*
    \sum_{l=1}^{n}\floor{n/l}^{l}
    */

    mint ans = 0;
    for(ll l = 1; l <= min(400000LL, n); l++){
        ans += mint(n/l).pow(l);
    }
    if(n <= 400000){
        cout << ans.val() << endl;
        return 0;
    }
    
    for(ll l = 1; l <= (n/400000); l++){
        ll pl = max(400001LL, n/(l+1)+1);
        ll pr = n/l;
        if(pl > pr) break;
        if(l == 1) ans += pr-pl+1;
        else ans += (mint(l).pow(pr+1)-mint(l).pow(pl))/(l-1);
    }
    cout << ans.val() << endl;

    return 0;
}