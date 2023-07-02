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
// https://atcoder.jp/contests/arc163/tasks/arc163_b

int main(){
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll l = a[0], r = a[1];
    vector<ll> b(n-2);
    rep(i, 2, n) b[i-2] = a[i];
    sort(b.begin(), b.end());

    ll ans = INF;
    rep(i, 0, n-m-1){
        ll tmp = 0;
        if(b[i] < l) tmp += l-b[i];
        if(r < b[i+m-1]) tmp += b[i+m-1]-r;
        chmin(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}