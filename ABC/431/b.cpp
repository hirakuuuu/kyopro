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
    int x; cin >> x;
    int n; cin >> n;
    vector<int> w(n);
    rep(i, 0, n) cin >> w[i];

    vector<int> f(n);
    int q; cin >> q;
    while(q--){
        int p; cin >> p; p--;
        if(f[p]){
            x -= w[p];
            f[p] = 0;
        }else{
            x += w[p];
            f[p] = 1;
        }
        cout << x << endl;
    }
    
    return 0;
}