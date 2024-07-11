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
山みたいな形なら max a で良い
連続した区間に対する操作 → 区間の端に着目
端のところで絶対値の差が高々2しか変化しない
下界があって、実際これは達成可能
操作を逆に見ると、必ず max(maxA, sum d) を1か2減らせる.
*/

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll mx = 0;
    rep(i, 0, n) chmax(mx, a[i]);
    ll sum = 0;
    rep(i, 0, n) sum += abs(a[i]-a[(i+1)%n]);
    cout << max(mx, sum/2) << endl;
    
    return 0;
}