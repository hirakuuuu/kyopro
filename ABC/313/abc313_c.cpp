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
// https://atcoder.jp/contests/abc313/tasks/abc313_c

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    rep(i, 0, n){
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end());
    vector<ll> b(n, sum/n);
    rep(i, 0, sum%n){
        b[i]++;
    }
    sort(b.begin(), b.end());

    ll ans = 0;
    rep(i, 0, n){
        ans += abs(a[i]-b[i]);
    }
    cout << ans/2 << endl;
    
    return 0;
}