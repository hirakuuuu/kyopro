#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/agc007/tasks/agc007_b

// int main(){
//     int n; cin >> n;
//     vector<int> p(n+1), rp(n+1);
//     rep(i, 1, n+1){
//         cin >> p[i];
//         rp[p[i]] = i;
//     }

//     vector<int> c(n+1);
//     iota(c.begin(), c.end(), 1e9-n);
//     vector<int> a(n+1), b(n+1);
//     b[0] = c[0] = INFINITY;
//     rep(i, 1, n+1){
//         // a[i], b[i]の値を決めたい
//         // a[i]+b[i] = c[rp[i]]
//         // a[i-1]<a[i]
//         // a[i]<=c[rp[n]]-1-(n-i)
//         // c[rp[i]]-a[i]<c[rp[i-1]]-a[i-1]
//         // 1+(n-i)<=c[rp[i]]-a[i]

//         a[i] = min(min(c[rp[n]], c[rp[i]])-1-(n-i), max(a[i-1], c[rp[i]]-c[rp[i-1]]+a[i-1])+1);
//         b[i] = c[rp[i]]-a[i];
//     }

//     rep(i, 1, n+1) cout << a[i] << (i < n ? ' ' : '\n');
//     rep(i, 1, n+1) cout << b[i] << (i < n ? ' ' : '\n');

//     return 0;
// }

int main(){
    int n; cin >> n;
    vector<int> p(n);
    rep(i, 0, n) cin >> p[i];
    int mx = 40000;
    vector<int> a(n), b(n);
    rep(i, 0, n){
        a[i] += mx*(i+1);
        a[p[i]-1] += i;
        b[n-i-1] += mx*(i+1);
    }
    rep(i, 0, n) cout << a[i] << (i == n-1? '\n': ' ');
    rep(i, 0, n) cout << b[i] << (i == n-1? '\n': ' ');
    return 0;
}