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

    ll n, d, a; cin >> n >> d >> a;
    vector<pair<ll, ll>> xh(n);
    rep(i, 0, n){
        cin >> xh[i].first >> xh[i].second;
    }

    sort(xh.begin(), xh.end());
    vector<ll> cnt(n+1);
    ll ans = 0;
    rep(i, 0, n){
        if(xh[i].second > cnt[i]*a){
            ll tmp = (xh[i].second-cnt[i]*a+a-1)/a;
            ans += tmp;
            cnt[i] += tmp;
            int pos = upper_bound(xh.begin(), xh.end(), make_pair(xh[i].first+2*d+1, 0LL))-xh.begin();
            cnt[pos] -= tmp;
        }
        cnt[i+1] += cnt[i];
    }

    cout << ans << endl;



    
    return 0;
}