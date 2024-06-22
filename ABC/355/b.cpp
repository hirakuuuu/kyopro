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
    vector<int> a(n), b(m);
    map<int, bool> is_a;
    rep(i, 0, n){
        cin >> a[i];
        is_a[a[i]] = true;
    }
    rep(i, 0, m) cin >> b[i];
    vector<int> c(n+m);
    rep(i, 0, n) c[i] = a[i];
    rep(i, n, n+m) c[i] = b[i-n];
    sort(c.begin(), c.end());
    rep(i, 0, n+m-1){
        if(is_a[c[i]] && is_a[c[i+1]]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}