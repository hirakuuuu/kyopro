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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto my_sqrt = [](ll x)->ll{ // sqrtの誤差がないバージョン
        int res = (int)sqrt(x);
        if((ll)res*res > x) res--;
        if((ll)(res+1)*(res+1) <= x) res++;
        return res;
    };

    int t; cin >> t;
    while(t--){
        ll k; cin >> k;
        ll sq = my_sqrt(k);

        ll ans = (sq-1)*(sq-1)*2+2*(sq-1);
        k -= sq*sq;
        if(inr(1, k, sq+1)){
            ans += (k-1)*2+1;
        }else if(inr(sq+1, k, 2*sq+1)){
            ans += (sq-1)*2+1+1+(k-sq-1)*2;
        }
        cout << ans << endl;

    }
    return 0;
}