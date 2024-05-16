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

*/

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<int> lis_l(n+1, IINF), lis_r(n+1, IINF);
    vector<int> cnt_l(n+1), cnt_r(n+1);
    rep(i, 0, n){
        int pos = lower_bound(lis_l.begin(), lis_l.end(), a[i])-lis_l.begin();
        lis_l[pos] = a[i];
        cnt_l[i] = pos;
    }
    rrep(i, n-1, 0){
        int pos = lower_bound(lis_r.begin(), lis_r.end(), a[i])-lis_r.begin();
        lis_r[pos] = a[i];
        cnt_r[i] = pos;
    }
    int ans = 0;
    rep(i, 0, n) chmax(ans, cnt_l[i]+1+cnt_r[i]);
    cout << ans << endl;


    return 0;
}