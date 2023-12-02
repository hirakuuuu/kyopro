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
// https://atcoder.jp/contests/abc330/tasks/abc330_c

int main(){
    ll d; cin >> d;
    vector<ll> x;
    for(ll i = 0; i <= 2000000; i++){
        ll tmp = i*i-d;
        x.push_back(tmp);
    }

    ll b = 9e18;
    for(ll i = 0; i <= 2000000; i++){
        auto itr = lower_bound(x.begin(), x.end(), -i*i);
        if(itr == x.end()) continue;
        ll l = *itr;
        chmin(b, abs(l+i*i));
        if(itr == x.begin()) continue;
        itr--;
        ll r = *itr;
        chmin(b, abs(r+i*i));
    }
    cout << b << endl;
    
    return 0;
}