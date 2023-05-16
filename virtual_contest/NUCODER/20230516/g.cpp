#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> sum(n+1);
    rep(i, 0, n) sum[i+1] = (sum[i]+a[i])%m;

    map<int, int> cnt;
    ll ans = 0;
    cnt[0] = 1;
    rep(r, 1, n+1){
        ans += cnt[sum[r]];
        cnt[sum[r]]++;
    }
    cout << ans << endl;

    
    return 0;
}