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
// 

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll ok = 0, ng = 9e18;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        ll tmp = 0, cnt = 0;
        rep(i, 0, n){
            tmp += a[i];
            if(tmp >= mid){
                tmp = 0;
                cnt++;
            }
        }
        if(cnt >= k) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    
    return 0;
}