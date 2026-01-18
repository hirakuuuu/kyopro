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
        vector<ll> a(n), b(n), c(n);
        ll rest = 0;
        vector<ll> div(3);
        rep(i, 0, n){
            cin >> a[i] >> b[i] >> c[i];
            ll d1 = min(a[i], b[i]);
            div[1] += d1;
            ll d2 = min(c[i], b[i]-d1);
            div[2] += d2;
            rest += min(d1, c[i]-d2);
        }
        if(div[1] <= div[2]){
            cout << div[1] << endl;
        }else{
            if(div[1]-rest >= div[2]+rest){
                cout << div[2]+rest << endl;
            }else{
                cout << (div[1]+div[2])/2 << endl;
            }
        }
        // cout << div[1] << ' ' << div[2] << endl;
    }
    
    return 0;
}