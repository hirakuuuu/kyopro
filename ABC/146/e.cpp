#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc146/tasks/abc146_e

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i] %= k;
    }
    if(k == 1){
        cout << 0 << endl;
        return 0;
    }


    vector<ll> sm(n+1);
    rep(i, 1, n+1) sm[i] = (sm[i-1]+a[i-1])%k;

    map<ll, ll> cnt;
    cnt[0] = 1;
    ll ans = 0;
    rep(r, 1, n+1){
        ll tmp = ((sm[r]-r)%k+k)%k;
        ans += cnt[tmp];
        cnt[tmp]++;

        if(r >= k-1){
            tmp = ((sm[r-k+1]-(r-k+1))%k+k)%k;
            cnt[tmp]--;
        }
    }
    cout << ans << endl;
    return 0;
}