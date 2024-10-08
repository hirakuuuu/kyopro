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

// オイラーのφ関数
ll euler_phi(ll n){
    ll ret = n;
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0){
            ret -= ret/i;
            while(n%i == 0) n /= i;
        }
    }
    if(n > 1) ret -= ret/n;
    return ret;
}

ll power(ll a, ll b, ll m=998244353){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    int t; cin >> t;
    while(t--){
        ll k; cin >> k;
        if(k%4 == 0 || k%5 == 0){
            cout << -1 << endl;
        }else{
            if(k%2 == 0) k /= 2;
            k *= 9;
            ll p = euler_phi(k);
            vector<ll> y;
            for(ll i = 1; i*i <= p; i++){
                if(p%i == 0){
                    y.push_back(i);
                    if(p/i != i) y.push_back(p/i);
                }
            }
            sort(y.begin(), y.end());
            for(auto yy: y){
                if(power(10, yy, k) == 1){
                    cout << yy << endl;
                    break;
                }
            }
        }
    }
    return 0;
}