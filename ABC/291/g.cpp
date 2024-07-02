#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

/*

論理演算は桁ごとに総和を計算してもよい -> 値が０，１になるので、見通しがよくなる
０，１の or は 反転して１から積を引いた値に変換できる（とりあえず、積の総和の形に帰着したい）
どっちか反転すると、添え字の和が等しくなるので、畳み込みができる

*/

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    vector<int> d(n);
    rep(i, 0, 5){
        vector<int> A(2*n), B(n);
        rep(j, 0, n){
            A[j] = A[j+n] = ~(a[j]>>i)&1;
            B[j] = ~(b[n-1-j]>>i)&1;
        }
        vector<int> c = atcoder::convolution(A, B);
        rep(j, 0, n){
            d[j] += (n-(c[n-1+j]))<<i;
        }
    }

    int ans = 0;
    rep(i, 0, n) chmax(ans, d[i]);
    cout << ans << endl;
    return 0;
}