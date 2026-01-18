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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;




    while(t--){
        ll n, a, b, c, d; cin >> n >> a >> b >> c >> d;
        vector<pair<ll, ll>> ope = {
            {2, a},
            {3, b},
            {5, c},
        };
        map<ll, ll> memo;
        memo[0] = 0;
        memo[1] = d;
        auto f = [&](auto self, ll x) -> ll {
            if(memo.count(x)) return memo[x];

            ll res = INF;
            if(x <= IINF) res = x*d;
            for(auto [m, cost]: ope){
                ll r = x%m;
                ll mi = cost;
                if((cost+d-1)/d > (x-r)/m*(m-1)) mi = ((x-r)/m*(m-1))*d;
                chmin(res, self(self, (x-r)/m)+mi+r*d);
               
                mi = cost;
                if((cost+d-1)/d > (x+(m-r)%m)/m*(m-1)) mi = ((x+(m-r)%m)/m*(m-1))*d;
                chmin(res, self(self, (x+(m-r)%m)/m)+mi+((m-r)%m)*d);
            }
            return memo[x] = res;
        };
        cout << f(f, n) << endl;

        // for(auto [key, val]: memo){
        //     cout << key << ' ' << val << endl;
        // }

    }
    
    return 0;
}