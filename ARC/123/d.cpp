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
c 全体に -1 をかけて a[i] = b[i]-c[i] とし、c を広義単調増加としても答えは変わらない
また、このとき、
- b[i+1] = b[i]+max(0, a[i+1]-a[i]);
- c[i+1] = c[i]+max(0, a[i]-a[i+1]);
と遷移することで、答えと隣接項の差が等しいような数列 b, c を得ることができる
絶対値の総和を最小にするには、中央値を０にするようにずらしてあげればよい.
*/

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll b = a[0], c = 0;
    vector<ll> B = {b, c};
    rep(i, 0, n-1){
        ll x = a[i+1]-a[i];
        if(x >= 0) b += x;
        else c -= x;
        B.push_back(b);
        B.push_back(c);
    }
    sort(B.begin(), B.end());
    ll p = B[n];
    ll ans = 0;
    rep(i, 0, 2*n) ans += abs(B[i]-p);
    cout << ans << endl;
    
    return 0;
}