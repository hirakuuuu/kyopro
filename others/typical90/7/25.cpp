#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

/*
f(m) として考えられる数はそんなに多くない
 0, 1, 2^x3^y5^z7^w と書けるやつだけ
これは 0<= x, y, z, w <= 40 としても 2.5e6程度

よって、 f(m) として考えられる数を全探索して、
m = b+f(m) について、条件を満たすかを判定
*/


int main(){
    ll n, b; cin >> n >> b;
    // f(m)として考えられる数を列挙
    ll mx = (ll)pow(9, 11);
    vector<ll> fm = {0LL};
    for(ll x = 1; x <= mx; x *= 2LL){
        for(ll y = 1; x*y <= mx; y *= 3LL){
            for(ll z = 1; x*y*z <= mx; z *= 5LL){
                for(ll w = 1; x*y*z*w <= mx; w *= 7LL){
                    fm.push_back(x*y*z*w);
                }
            }
        }
    }
    sort(fm.begin(), fm.end());
    fm.erase(unique(fm.begin(), fm.end()), fm.end());

    // 各桁の積を計算
    auto f = [](ll x) -> ll {
        ll res = 1;
        string tmp = to_string(x);
        for(auto t: tmp){
            res *= (ll)(t-'0');
        }
        return res;
    };

    // 各f(m)について、条件を満たすかを判定
    ll ans = 0;
    for(auto ff: fm){
        ll m = ff+b;
        if(1 <= m && m <= n && f(m) == ff) ans++;
    }
    cout << ans << endl;

    
    return 0;
}