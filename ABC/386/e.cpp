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
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll tot = 0;
    rep(i, 0, n) tot ^= a[i];
    ll tmp = 0;
    if(k <= n/2){
        auto f = [&](auto self, int pos, int rest) -> ll {
            if(n-pos < rest) return 0;
            if(rest == 0) return tmp;
            if(pos == n) return 0;
            
            tmp ^= a[pos];
            ll res1 = self(self, pos+1, rest-1);
            tmp ^= a[pos];
            ll res2 = self(self, pos+1, rest);
            return max(res1, res2);
        };

        cout << f(f, 0, k) << endl;
    }else{
        auto f = [&](auto self, int pos, int rest) -> ll {
            if(n-pos < rest) return 0;
            if(rest == 0) return tot^tmp;
            if(pos == n) return 0;
            
            tmp ^= a[pos];
            ll res1 = self(self, pos+1, rest-1);
            tmp ^= a[pos];
            ll res2 = self(self, pos+1, rest);
            return max(res1, res2);
        };

        cout << f(f, 0, n-k) << endl;
    }

    return 0;
}