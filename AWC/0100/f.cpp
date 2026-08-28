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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    ll k; cin >> k;
    vector<ll> v(n);
    
    rep(i, 0, n){
        cin >> v[i];
    }
    ll ans = 0;
    ll sum = 0;
    int r = 0;
    for(int l = 0; l < n; ){
        while(r < n && sum < k){
            sum += v[r];
            r++;
        }
        // cout << sum << ' ' << l << ' ' << r << endl;
        if(sum >= k){
            ans += n-r+1;
        }
        sum -= v[l];
        l++;
    }
    cout << ans << endl;
    return 0;
}