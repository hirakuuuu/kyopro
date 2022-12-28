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
// https://atcoder.jp/contests/abc241/tasks/abc241_e

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<ll> seen(n);
    vector<ll> seen_acc(n+1);
    ll pos = 0, cnt = 1, ans = 0;
    while(seen[pos] == 0 and k > 0){
        seen[pos] = cnt;
        ans += a[pos];
        seen_acc[cnt] = ans;
        cnt++;
        pos = ans%n;
        k--;
    }

    if(k == 0){
        cout << ans << endl;
    }else{
        ll l = seen[pos], r = cnt-1;
        ans += (seen_acc[r]-seen_acc[l-1])*(k/(r-l+1));
        k %= (r-l+1);
        ans += seen_acc[l+k-1]-seen_acc[l-1];
        cout << ans << endl;
    }

    
    return 0;
}