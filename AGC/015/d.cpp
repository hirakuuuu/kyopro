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
    auto f = [&](auto self, ll a, ll b) -> ll {
        vector<ll> bit_a, bit_b;
        rep(i, 0, 60){
            if((a>>i)&1) bit_a.push_back(i);
            if((b>>i)&1) bit_b.push_back(i);
        }

        if(a == 0LL){
            return b+1;
        }

        
        ll res = 0;
        if(bit_a.back() < bit_b.back()){
            res = (1LL<<(bit_b.back()))-a;
            ll l = 1, r = (1LL<<(bit_b.back()))-a;
            if(bit_b.size() > 1){
                l += (1LL<<(bit_b[bit_b.size()-2]+1))-1;
            }
            // cout << l << ' ' << r << endl;
            if(l+r > 1LL<<(bit_b.back())) res += 1LL<<(bit_b.back());
            else res += l+r;

            return res;
        }
        return self(self, a-(1LL<<(bit_b.back())), b-(1LL<<(bit_b.back())));
    };
    ll a, b; cin >> a >> b;
    
    cout << f(f, a, b) << endl;

    return 0;
}