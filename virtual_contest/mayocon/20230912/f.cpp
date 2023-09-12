#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    double X, Y, R; cin >> X >> Y >> R;
    double a = 10000;
    ll x = round(X*a), y = round(Y*a), r = round(R*a);
    ll ans = 0;
    ll i = y-r;
    if(i%10000 != 0){
        if(i < 0) i -= i%10000;
        else i += (10000-i%10000)%10000;
    }
    for(ll ny = i; ny <= y+r; ny += 10000){
        ll d = r*r-(y-ny)*(y-ny);
        ll ok = 0, ng = 2*IINF+1;

        while(ng-ok > 1){
            ll mid = (ok+ng)/2;
            if(mid*mid <= d) ok = mid;
            else ng = mid;
        }
        ll m = (x-ok+9999)/10000;
        if(x-ok < 0) m = (x-ok)/10000;
        ll M = (x+ok)/10000;
        if(x+ok < 0) M = (x+ok-9999)/10000;
        ans += M-m+1;
    }
    cout << ans << endl;

    
    return 0;
}