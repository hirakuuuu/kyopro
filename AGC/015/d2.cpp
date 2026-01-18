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
    auto f = [&](ll a, ll b) -> ll {
        ll c = b-a+1;
        set<ll> s;
        for(int i = 1; i < 1<<c; i++){
            ll num = 0;
            for(int j = 0; j < c; j++){
                if((i>>j)&1) num |= a+j;
            }
            s.insert(num);
        }
        return s.size();
    };
    for(ll a = 1; a <= 10; a++){
        for(ll b = a; b <= 20; b++){
            cout << "a = " << a << ", b = " << b << ": " << f(a, b) << endl;
        }
    }
    return 0;
}