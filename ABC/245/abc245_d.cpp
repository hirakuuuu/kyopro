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
// https://atcoder.jp/contests/abc245/tasks/abc245_d

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n+1), c(n+m+1);
    rep(i, 0, n+1) cin >> a[i];
    rep(i, 0, n+m+1) cin >> c[i];
    vector<int> b(m+1);
    b[m] = c[n+m]/a[n];
    rrep(i, n+m-1, n){
        int tmp = 0;
        rep(j, 0, n+1){
            if(0 <= i-j && i-j <= m){
                tmp += a[j]*b[i-j];
            }
        }
        b[i-n] = (c[i]-tmp)/a[n];
    }
    rep(i, 0, m+1) cout << b[i] << ' ';
    cout << endl;

    return 0;
}