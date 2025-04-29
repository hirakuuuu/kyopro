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
    int n, m; cin >> n >> m;
    mint ans = 0;
    mint mn = mint(m).pow(n), mm = m;
    rep(i, 1, m+1){
        mint tmp = i;
        mint now1 = mn*n;
        if(i > 1) now1 = (mm-i+1)*(mn-mint(m-i+1).pow(n))/mint(i-1);
        
        mint now2 = (mm-i)*(mn-mint(m-i).pow(n))/mint(i);

        ans += tmp*(now1-now2);
    }
    cout << ans.val() << endl;
    return 0;
}