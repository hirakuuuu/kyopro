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
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        if(n >= 32){
            a[0] = 2;
        }else{
            ll num = (1LL<<(n-1))-1;
            ll x = (k+(num-1))/num+1;
            a[0] = max(2LL, x);
        }
        rep(i, 1, n){
            if(k){
                if(k > a[i-1]-1){
                    a[i] = a[i-1]*2-1;
                    k -= a[i-1]-1;
                }else{
                    a[i] = a[i-1]+k;
                    k = 0;
                }
            }else{
                a[i] = a[i-1];
            }
        }
        rep(i, 0, n){
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}
