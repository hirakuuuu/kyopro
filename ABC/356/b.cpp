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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m);
    rep(i, 0, m) cin >> a[i];
    vector<int> b(m);
    rep(i, 0, n){
        rep(j, 0, m){
            int x; cin >> x;
            b[j] += x;
        }
    }
    rep(i, 0, m){
        if(b[i] < a[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    
    return 0;
}