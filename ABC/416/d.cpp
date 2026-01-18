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
        ll n, m; cin >> n >> m;
        vector<ll> a(n), b(n);
        ll sum = 0;
        rep(i, 0, n) cin >> a[i], sum += a[i];
        rep(i, 0, n) cin >> b[i], sum += b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int ok = n, ng = -1;
        while(ok-ng > 1){
            int mid = (ok+ng)/2;
            bool f = true;
            rep(i, mid, n){
                if(a[i]+b[n-1+mid-i] < m) f = false;
            }
            if(f) ok = mid;
            else ng = mid;
        }
        sum -= m*(n-ok);
        cout << sum << endl;
    }
    
    return 0;
}