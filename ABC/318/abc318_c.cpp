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
// https://atcoder.jp/contests/abc318/tasks/abc318_c

int main(){
    ll n, d, p; cin >> n >> d >> p;
    vector<ll> f(n);
    ll ans = 0;
    rep(i, 0, n){
        cin >> f[i];
        ans += f[i];
    }
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());
    
    ll day = 0, cur = ans;
    while(day < n){
        ll tmp = 0;
        rep(i, day, min(day+d, n)){
            tmp += f[i];
        }
        day += d;
        cur += p-tmp;
        chmin(ans, cur);
    }

    cout << ans << endl;



    
    return 0;
}