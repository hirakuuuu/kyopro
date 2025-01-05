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
    int n, r; cin >> n >> r;

    rep(i, 0, n){
        int d, a; cin >> d >> a;
        if(d == 1){
            if(inr(1600, r, 2800)) r += a;
        }else{
            if(inr(1200, r, 2400)) r += a;
        }
    }
    cout << r << endl;
    return 0;
}