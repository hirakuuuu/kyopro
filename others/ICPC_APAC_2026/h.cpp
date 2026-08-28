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
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    ll g = 0;
    rep(i, 1, n) g += abs(a[i]-a[i-1]);
    ll G = abs(a[1]-a[0]);
    
    rep(i, 2, n){
        if(a[i] == a[i-1]) continue;
        if(G == 0) G = abs(a[i]-a[i-1]);
        else G = gcd(G, abs(a[i]-a[i-1]));
    }
    ll mi = a[0];
    if(G != 0){
        if(a[0]%(G*2) == 0) chmin(mi, G*2);
        else chmin(mi, a[0]%(G*2));
    }
    cout << mi+g << endl;

    return 0;
}