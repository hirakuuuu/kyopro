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

木の次数を１増やすことによって増える値は (2*d[i]+1)*a[i]
これが小さいものから増やしていけばよい
正当性は (2*d[i]+1)*a[i] は単調増加なので, ある時点で最小でないものは、それ以降にとれるようになったどの値よりも小さい.
つまり, 値が最も小さいものをとっても損をすることがない.

貪欲にとっていくのを施行から
*/

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    
    vector<ll> d(n, 1);
    ll ans = 0;
    rep(i, 0, n) ans += a[i];
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    rep(i, 0, n) que.push({a[i]*(d[i]*2+1), i});

    rep(i, 0, n-2){
        auto [tmp, ind] = que.top(); que.pop();
        ans += tmp;
        d[ind]++;
        que.push({a[ind]*(d[ind]*2+1), ind});
    }
    cout << ans << endl;



    
    return 0;
}