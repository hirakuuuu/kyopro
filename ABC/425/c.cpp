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
    int n, q; cin >> n >> q;
    vector<ll> a(2*n);
    rep(i, 0, n){
        cin >> a[i];
    }
    rep(i, n, 2*n){
        a[i] = a[i-n];
    }
    vector<ll> acc(2*n+1);
    rep(i, 0, 2*n){
        acc[i+1] = acc[i]+a[i];
    }



    int off = 0;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int c; cin >> c;
            off = (off+c)%n;
        }else{
            int l, r; cin >> l >> r; l--;
            cout << acc[r+off]-acc[l+off] << endl;

        }
    }
    return 0;
}