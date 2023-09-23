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
// https://atcoder.jp/contests/abc321/tasks/abc321_e

ll power(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a;
        a = a*a;
        b /= 2;
    }
    return res;
}

int main(){
    int t; cin >> t;
    while(t--){
        ll n, x, k; cin >> n >> x >> k;
        ll d = 1, m = 1;
        while(m < n){
            m += (1LL<<d);
            d++;
        }
        ll dx = 1;
        m = 1;
        while(m < x){
            m += (1LL<<dx);
            dx++;
        }

        ll ans = 0;
        if(d-dx >= k && power(2, k)*x <= n) ans += min(n, (ll)power(2, k)*(x+1)-1)-power(2, k)*x+1;
        ll _x = x;
        x /= 2;
        k--;
        while(x && k >= 0){
            if(k == 0){
                ans++;
            }else if(2*x == _x){
                if(d-dx >= k-1 && power(2, k-1)*(2*x+1) <= n) ans += min(n, (ll)power(2, k-1)*(2*x+2)-1)-power(2, k-1)*(2*x+1)+1;
            }else{
                if(d-dx >= k-1 && power(2, k-1)*(2*x) <= n) ans += min(n, (ll)power(2, k-1)*(2*x+1)-1)-power(2, k-1)*(2*x)+1;
            }
            _x = x;
            x /= 2;
            k--;
            dx--;
        }
        cout << ans << endl;
    }
    
    
    return 0;
}