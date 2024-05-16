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

/*
期待値の線形性、こういうのは未証明でも投げる方が良い
*/

int main(){
    int n; cin >> n;
    vector<long double> cnt(101);
    long double ans = 0.0;
    rep(i, 0, n){
        int l, r; cin >> l >> r;
        long double sum = 0.0;
        long double p = 1.0/(double)(r-l+1);
        rrep(j, 100, r+1) sum += cnt[j];
        rrep(j, r, l){
            ans += p*sum;
            sum += cnt[j];
        }
        rep(j, l, r+1){
            cnt[j] += p;
        }
    }

    cout << setprecision(20) << ans << endl;

    return 0;
}