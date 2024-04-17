#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll sum = 0;
    rep(i, 0, n) sum += a[i];
    vector<ll> y;
    for(ll i = 1; i*i <= sum; i++){
        if(sum%i == 0){
            y.push_back(i);
            if(sum/i != i) y.push_back(sum/i);
        }
    }
    sort(y.rbegin(), y.rend());
    for(auto m: y){
        vector<ll> b(n), c(n);
        rep(i, 0, n){
            b[i] = a[i]%m;
        }
        sort(b.begin(), b.end());
        int l = 0, r = n-1;
        ll cnt = 0;
        while(l < r){
            ll tmp = min(b[l], m-b[r]);
            cnt += tmp;
            b[l] -= tmp;
            b[r] += tmp;
            if(b[l]%m == 0) l++;
            if(b[r]%m == 0) r--;
        }
        // cout << m << ' ' << cnt << endl;
        if(cnt <= k){
            cout << m << endl;
            return 0;
        }
    }
    

    
    return 0;
}
