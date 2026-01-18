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
        int n; cin >> n;
        ll m; cin >> m;
        vector<ll> a(n+5);
        a[0] = 1;
        a[1] = 2;
        a[2] = 7;
        rep(i, 3, n+1){
            a[i] = a[i-1]*i;
            a[i] += (2*a[i-1]-a[i-2])%m+m;
            a[i] %= m;
            
            
            cout << i << ' ' << a[i] << endl;
            a[i] += a[i-2]*i;
            a[i] += a[i-1];
            a[i] += m-1;
            a[i] %= m;
            rep(j, 1, i){
                a[i] += ((m-i*(i+1-j))%m+m)%m;
                a[i] %= m;
            }
            a[i] %= m;
            
        }
        cout << a[n] << endl;
    }
    
    return 0;
}