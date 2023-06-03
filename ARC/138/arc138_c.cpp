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
// https://atcoder.jp/contests/arc138/tasks/arc138_c

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<pll> b(n);
    rep(i, 0, n) b[i] = {a[i], i};
    sort(b.begin(), b.end());

    vector<ll> c(n);
    rep(i, n/2, n) c[b[i].second] = 1;

    vector<ll> ruiseki(n+1);
    rep(i, 1, n+1){
        if(c[i-1]) ruiseki[i] = ruiseki[i-1]+1;
        else ruiseki[i] = ruiseki[i-1]-1;
    }

    ll pos = 0, tmp = 0;
    rep(i, 0, n){
        if(tmp < ruiseki[i+1]){
            pos = i+1;
            tmp = ruiseki[i+1];
        }
    }

    ll ans = 0;
    rep(i, 0, n){
        if(c[i]) ans += a[i];
    }
    cout << pos << ' ' << ans << endl;


    
    return 0;
}