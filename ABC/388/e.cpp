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

    int ok = 0, ng = n/2+1;
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        // 大きい方 mid 個と小さい方 mid 個を合わせる
        vector<int> mx(mid), mi(mid);
        rep(i, 0, mid) mi[i] = a[i];
        rep(i, 0, mid) mx[i] = a[(n-mid)+i];



        bool f = true;
        rep(i, 0, mid){
            if(mi[i]*2 > mx[i]) f = false;
        }
        if(f) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}