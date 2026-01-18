#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;
    while(t--){
        ll n, a, b; cin >> n >> a >> b;
        if(a > b) swap(a, b);
        if(a+b > n){
            cout << 0 << endl;
            continue;
        }


        mint ans = 0;
        // 辺の長さが b より大きい
        ans += (mint(n-b+1)*mint(n-b)/2)*(mint(1+n-a-b+1)*mint(n-a-b+1)/2)*8;
        ans -= (mint(1+n-a-b+1)*mint(n-a-b+1)/2)*(mint(1+n-a-b+1)*mint(n-a-b+1)/2)*4;

        // 片方が b
        ans += mint(b-a+1)*mint(n-b+1)*(mint(1+n-a-b+1)*mint(n-a-b+1)/2)*4;

        cout << ans.val() << endl;
    }
    return 0;
}