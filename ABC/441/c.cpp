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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, k; cin >> n >> k;
    ll x; cin >> x;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll sum = 0;
    rep(i, 0, k) sum += a[i];
    if(sum < x){
        cout << -1 << endl;
        return 0;
    }

    rep(i, 0, k){
        sum -= a[i];
        if(sum < x){
            cout << n-i << endl;
            break;
        }
    }
    return 0;
}