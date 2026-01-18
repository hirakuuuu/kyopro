#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int gcd(int a, int b){
    if(a == 0 && b == 0) return 1;
    if(a == 0) return b;
    if(b == 0) return a;

    if(a%b == 0){
      return b;
    }else{
      return gcd(b, a%b);
    }
}


int main(){
    ios::sync_with_stdio(false);    
    std::cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> x(n), y(n);
    rep(i, 0, n){
        cin >> x[i] >> y[i];
    }
    map<tuple<int, int, ll>, int> cnt2;
    map<pair<int, int>, int> cnt;

    rep(i, 0, n){
        rep(j, i+1, n){
            
            int a = x[i]-x[j];
            int b = y[i]-y[j];
            if(a < 0){
                a = -a;
                b = -b;
            }else if(a == 0 && b < 0){
                b = -b;
            }
            int g = gcd(abs(a), abs(b));
            a /= g;
            b /= g;


            cnt[{a, b}]++;
            ll d = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            cnt2[{a, b, d}]++;
        }
    }

    ll ans = 0;
    for(auto [key, val]: cnt){
        // auto [a, b] = key;
        // cout << a << ' ' << b << ' ' << val << endl;
        ans += (ll)val*(val-1)/2;
    }
    ll rest = 0;
    for(auto [key, val]: cnt2){
        // cout << a << ' ' << b << ' ' << c << ' ' << val << endl;
        rest += (ll)val*(val-1)/2;
    }
    cout << ans-rest/2 << endl;



    
    return 0;
}