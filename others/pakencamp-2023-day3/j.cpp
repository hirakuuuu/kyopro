#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll f(ll a){
    if(a%4 == 0) return a;
    if(a%4 == 3) return 0;
    if(a%4 == 1) return 1;
    return a^1;
}

int main(){
    int t; cin >> t;
    while(t--){
        ll l, r; cin >> l >> r;
        if(l == r){
            if(l == 0) cout << 1 << endl;
            else cout << 2 << endl;
            continue;
        }
        if(l == 0) l = 1;
        ll b = 0;
        rep(i, 0, 60){
            if((l>>i)&1){
                b++;
            }else{
                ll p = (1LL<<i)-(l&((1LL<<i)-1));
                if(l+p <= r) b++;
            }
        }
        ll ans = 1LL<<b;
        if((f(r)^f(l-1)) == 0LL){
            if(r-l+1 < 60) chmin(ans, (1LL<<(r-l)));
        }else{
            if(r-l+1 < 60) chmin(ans, 1<<(r-l+1));
        }
        
        cout << ans << endl;
    }
    
    return 0;
}