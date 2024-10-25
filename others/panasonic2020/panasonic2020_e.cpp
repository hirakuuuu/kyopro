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
    string a, b, c; cin >> a >> b >> c;
    int A = (int)a.size(), B = (int)b.size(), C = (int)c.size();

    vector<bool> ab(20005, true), ac(20005, true), bc(20005, true);
    int offset = 10000;
    rep(i, 0, A) rep(j, 0, B){
        if(!(a[i] == b[j] || a[i] == '?' || b[j] == '?')) ab[i-j+offset] = false;
    }
    rep(i, 0, A) rep(j, 0, C){
        if(!(a[i] == c[j] || a[i] == '?' || c[j] == '?')) ac[i-j+offset] = false;
    }
    rep(i, 0, B) rep(j, 0, C){
        if(!(b[i] == c[j] || b[i] == '?' || c[j] == '?')) bc[i-j+offset] = false;
    }

    int ans = IINF;
    rep(i, -4000, 4001) rep(j, -4000, 4001){
        if(ab[i+offset] && ac[j+offset] && bc[j-i+offset]){
            int L = min(0, min(i, j));
            int R = max(A, max(i+B, j+C));
            chmin(ans, R-L);
        }
    }
    cout << ans << endl;
    
    return 0;
}