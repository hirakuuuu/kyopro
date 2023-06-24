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
// https://atcoder.jp/contests/arc147/tasks/arc147_c

int main(){
    ll n; cin >> n;
    vector<ll> l(n), r(n);
    rep(i, 0, n){
        cin >> l[i] >> r[i];
    }

    sort(l.begin(), l.end(), greater<>());
    sort(r.begin(), r.end());

    ll ans = 0;
    rep(i, 0, n){
        ans += max(0LL, l[i]-r[i])*(n-1-2*i);
    }

    cout << ans << endl;

    
    return 0;
}