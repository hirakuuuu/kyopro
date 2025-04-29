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
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<ll> acc(n+1);
    rep(i, 0, n){
        ll tmp = a[i]+acc[i];
        acc[i+1] += 1;
        if(tmp+i+1 <= n) acc[tmp+i+1] -= 1, a[i] -= tmp;
        else acc[n] -= 1, a[i] -= n-1-i;
        acc[i+1] += acc[i];
    }
    rep(i, 0, n){
        cout << a[i]+acc[i] << ' ';
    }
    cout << endl;
    return 0;
}