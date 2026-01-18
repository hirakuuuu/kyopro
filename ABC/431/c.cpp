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
    int n, m; cin >> n >> m;
    int k; cin >> k;
    vector<ll> h(n), b(m);
    rep(i, 0, n) cin >> h[i];
    rep(i, 0, m) cin >> b[i];
    sort(h.begin(), h.end());
    sort(b.begin(), b.end());


    bool f = true;
    rep(i, 0, k){
        if(h[k-1-i] > b[m-1-i]){
            f = false;
            break;
        }
    }

    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}