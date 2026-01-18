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
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    map<ll, ll> cnt3, cnt7;
    ll ans = 0;
    rep(i, 0, n){
        if(a[i]%3 == 0) cnt3[a[i]/3]++;
        if(a[i]%7 == 0) cnt7[a[i]/7]++;
        if(a[i]%5 == 0){
            ans += cnt3[a[i]/5]*cnt7[a[i]/5];
        }
    }
    cnt3.clear(), cnt7.clear();
    rrep(i, n-1, 0){
        if(a[i]%3 == 0) cnt3[a[i]/3]++;
        if(a[i]%7 == 0) cnt7[a[i]/7]++;
        if(a[i]%5 == 0){
            ans += cnt3[a[i]/5]*cnt7[a[i]/5];
        }
    }
    cout << ans << endl;
    return 0;
}