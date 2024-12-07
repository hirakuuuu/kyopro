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
    int vol = 0, pre = -1;
    rep(i, 0, n){
        int t, v; cin >> t >> v;
        if(pre != -1){
            // pre から t-1 までの分を減らす
            if(vol >= t-pre) vol -= t-pre;
            else vol = 0;
        }
        vol += v;
        pre = t;
    }
    cout << vol << endl;
    return 0;
}