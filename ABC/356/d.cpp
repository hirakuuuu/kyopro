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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n, m; cin >> n >> m;
    mint ans = 0;
    rrep(i, 60, 0){
        if(!((m>>i)&1)) continue;
        if((n>>i)&1){
            ans += mint((n>>(i+1)))*mint(1LL<<i);
            ans += mint((n&((1LL<<i)-1))+1);
        }else{
            ans += mint((n>>(i+1)))*mint(1LL<<i);
        }
        // cout << ans.val() <<endl;
    }
    cout << ans.val() << endl;

    return 0;
}