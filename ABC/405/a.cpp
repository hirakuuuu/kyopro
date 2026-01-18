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
    int r, x; cin >> r >> x;
    if(x == 1){
        if(1600 <= r && r < 3000) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        if(1200 <= r && r < 2400) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}