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

/*
あまりに着目したのはOK
だけど，x > y のときに余りが y 以上でわたる可能性があるのを見逃していた
*/

int main(){
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    bool f = false;
    rep(i, 0, n){
        if(a[i]%(x+y) >= x) f = true;
    }
    if(!f){
        cout << "Second" << endl;
    }else if(x <= y){
        cout << "First" << endl;
    }else{
        f = false;
        rep(i, 0, n){
            if(a[i]%(x+y) >= x) a[i] -= x;
            if(a[i]%(x+y) >= y) f = true;
        }
        if(f) cout << "Second" << endl;
        else cout << "First" << endl;
    }
    
    return 0;
}