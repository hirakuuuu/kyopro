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
// 

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m), c(n+m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    rep(i, 0, n) c[i] = a[i];
    rep(i, n, n+m) c[i] = b[i-n];
    sort(c.begin(), c.end());
    map<int, int> ind;
    rep(i, 0, n+m) ind[c[i]] = i+1;

    rep(i, 0, n) cout << ind[a[i]] << ' ';
    cout << endl;
    rep(i, 0, m) cout << ind[b[i]] << ' ';
    cout << endl;

    
    return 0;
}