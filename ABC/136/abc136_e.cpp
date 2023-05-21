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
// https://atcoder.jp/contests/abc136/tasks/abc136_e

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll sum = 0;
    rep(i, 0, n) sum += a[i];

    ll ans = 1;
    vector<ll> yakusu;
    for(ll i = 1; i*i <= sum; i++){
        if(sum%i == 0){
            yakusu.push_back(i);
            if(i != sum/i) yakusu.push_back(sum/i);
        }
    }
    for(auto y: yakusu){
        vector<ll> b = a;
        rep(i, 0, n) b[i] %= y;
        sort(b.begin(), b.end());
        ll l = 0, r = n-1, cnt = 0;
        while(r > l){
            ll tmp = min(b[l], y-b[r]);
            cnt += tmp;
            b[r] += tmp;
            b[l] -= tmp;
            if(b[r]%y == 0) r--;
            if(b[l]%y == 0) l++;
        }
        if(cnt <= k) chmax(ans, y);
    }
    cout << ans << endl;
    
    return 0;
}