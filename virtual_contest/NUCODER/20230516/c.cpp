#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(ll i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll f(ll x){
    return x*x*x*x*x;
}

int main(){
    ll x; cin >> x;
    rep(a, -1005, 1005){
        rep(b, -1005, 1005){
            if(f(a)-f(b) == x){
                cout << a << ' ' << b << endl;
                return 0;
            }
        }
    }
    
    return 0;
}