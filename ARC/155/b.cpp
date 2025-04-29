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
    int q; cin >> q;
    set<ll> s;
    s.insert(-INF);
    s.insert(INF);
    {
        ll a, b; cin >> a >> b;
        s.insert(a-b);
        s.insert(a+b);
    }

    auto f = [&](ll l, ll r, ll x) -> ll {
        if((l+r)%2 == 0 && x == (l+r)/2) return (l+r)/2;
        if(x <= (l+r)/2) return x-l;
        return r-x;
    };

    while(q--){
        int t; cin >> t;
        ll a, b; cin >> a >> b;
        if(t == 1){
            s.insert(a-b);
            s.insert(a+b);
        }else{
            auto itr_l = prev(s.upper_bound(a));
            auto itr_r = s.lower_bound(b);
            if(prev(itr_r) != itr_l){
                cout << 0 << endl;
            }else{
                ll l = *itr_l, r = *itr_r;
                cout << min(f(l, r, a), f(l, r, b)) << endl;
            }
        }

    }
    
    return 0;
}