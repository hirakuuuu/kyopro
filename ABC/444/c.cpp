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
    ll n; cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    rep(i, 0, n){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    if(n == 1){
        cout << a[0] << endl;
        return 0;
    }

    // a[n-1] or a[n-1]+a[0];
    {
        // a[n-1];
        vector<ll> b = a;
        while(!b.empty() && b.back() == a[n-1]) b.pop_back();
        bool ok = (b.size()%2 == 0);
        rep(i, 0, b.size()/2){
            if(b[i]+b[(int)b.size()-1-i] != a[n-1]) ok = false;
        }
        if(ok) cout << a[n-1] << ' ';
    }
    {
        // a[n-1]+a[0]
        vector<ll> b = a;
        bool ok = (b.size()%2 == 0);
        rep(i, 0, n/2){
            if(b[i]+b[(int)b.size()-1-i] != a[n-1]+a[0]) ok = false;
        }
        if(ok) cout << a[n-1]+a[0] << ' ';
    }
    cout << endl;
    return 0;
}