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

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    map<ll, ll> cnt;
    vector<ll> sum(n+1);
    ll ans = 0;
    cnt[0] = 1;
    rep(i, 1, n+1){
        if(i >= k){
            ll tmp = (sum[i-k]-i)%k;
            if(tmp < 0) tmp += k;
            cnt[tmp]--;
        }
        sum[i] = sum[i-1]+a[i];
        ll tmp = (sum[i]-i)%k;
        if(tmp < 0) tmp += k;
        ans += cnt[tmp];
        cnt[tmp]++;
    }

    cout << ans << endl;





    
    return 0;
}