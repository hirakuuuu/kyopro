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
    ll len = 0;
    string s;
    rep(i, 0, n){
        char c; cin >> c;
        ll l; cin >> l;
        if(len+l > 100){
            cout << "Too Long" << endl;
            return 0;
        }
        rep(j, 0, l) s += c;
        len += l;
    }
    cout << s << endl;
    
    return 0;
}