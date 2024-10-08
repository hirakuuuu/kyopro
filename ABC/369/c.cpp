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

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> d(n-1);
    rep(i, 0, n-1) d[i] = a[i+1]-a[i];

    ll ans = n;
    for(int i = 0; i < n-1;){
        int j = i;
        while(j < n-1 && d[i] == d[j]) j++;
        ans += (ll)(j-i)*(j-i+1)/2;
        i = j;
    }
    cout << ans << endl;

    return 0;
}