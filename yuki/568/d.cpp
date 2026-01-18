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
    int t; cin >> t;
    while(t--){
        ll r, c; cin >> r >> c;
        if(r == 1){
            cout << 0 << endl;
            continue;
        }


        
        ll mr = 1, mc = 1;
        while(mr*2 <= r){
            mr *= 2;
            mc += 1;
        }
        ll u = max(mr-1, mc-1);

        auto f = [&](auto self, ll pr, ll pc) -> ll {
            if(c == pc){
                return r-pr;
            }
            if(r <= pr){
                ll _c = c;
                while((r>>_c&1)){
                    _c++;
                }
                ll g = (1LL<<_c)-(r&(((1LL<<_c)-1)))-1;
                if(c < _c){
                    return max(pr-r+max(0LL, _c-c-g), pc-c);
                }
                return max(pr-r, pc-c);
            }

            ll nc = pc-1;
            ll nr = pr+(1LL<<(nc-1));
            return (nr-pr)+self(self, nr, nc);
        };
        ll d = f(f, mr, mc);
        // cout << u << ' ' << d << endl;
        cout << u+d << endl;
    }
    return 0;
}