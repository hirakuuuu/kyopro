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
    ll n, m; cin >> n >> m;
    vector<ll> x(m);

    map<ll, ll> a;

    ll sum = 0, tmp = 0;
    rep(i, 0, m){
        cin >> x[i];
    }
    rep(i, 0, m){
        ll A; cin >> A;
        a[x[i]] = A;
        sum += A;
        tmp += A*x[i];
    }
    sort(x.begin(), x.end());
    if(sum != n){
        cout << -1 << endl;
        return 0;
    }
    if(x[0] != 1){
        cout << -1 << endl;
        return 0;
    }
    ll acc = a[1];
    // ll ans = 0;
    rep(i, 1, m){
        if(x[i]-x[i-1] > acc){
            cout << -1 << endl;
            return 0;
        }
        acc -= x[i]-x[i-1];
        acc += a[x[i]];
    }

    cout << n*(n+1)/2-tmp << endl;
    
    return 0;
}