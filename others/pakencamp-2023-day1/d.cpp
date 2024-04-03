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
// https://atcoder.jp/contests/pakencamp-2023-day1/tasks/d

int main(){
    ll k; cin >> k;
    vector<ll> x(2), y(2);
    rep(i, 0, 2) cin >> x[i] >> y[i];
    x[1] -= x[0];
    y[1] -= y[0];
    x[1] = abs(x[1]);
    y[1] = abs(y[1]);
    ll ans = abs(x[1]-y[1]+2*k-1)/(2*k);
    //((x[1]-y[1])/2, -(x[1]-y[1])/2);
    if(x[1] > y[1]){
        if((x[1]-y[1])%2 == 0){
            cout << ans+(x[1]-(x[1]-y[1])/2+k-1)/k << endl;
        }else{
            cout << ans+(x[1]-(x[1]-y[1])/2+k-1)/k << endl;
        }
    }
    cout << ans
    return 0;
}