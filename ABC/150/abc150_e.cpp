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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int n; cin >> n;
    vector<ll> c(n);
    rep(i, 0, n) cin >> c[i];
    sort(c.begin(), c.end());
    mint ans = 0, two = mint(2).pow(n-1); 
    rep(i, 0, n){
        mint cnt = mint(2).pow(2*i+(n-i));
        if(n-i-2 >= 0) cnt *= mint(2).pow(n-i-1)+mint(n-i-1)*mint(2).pow(n-i-2);
        else cnt *= mint(2).pow(n-i-1);
        cout << c[i] << ' ' << cnt.val() << endl;
        ans += c[i]*cnt;
    }
    cout << ans.val() << endl;    
    return 0;
}