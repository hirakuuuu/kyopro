#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    ll L, R; cin >> L >> R;
    auto f = [](ll l, ll r) -> ll{
        ll l_ = l, tmp = 1;
        while(l_%2 == 0 && (l_+1)*tmp <= r){
            l_ /= 2;
            tmp *= 2;
        }
        if((l_+1)*tmp > r){
            l_ *= 2;
            tmp /= 2;
        }
        return (l_+1)*tmp;
    };
    vector<pair<ll, ll>> ans;
    while(L < R){
        ll r_ = f(L, R);
        ans.push_back({L, r_});
        L = r_;
    }
    cout << ans.size() << endl;
    for(auto [l, r]: ans){
        cout << l << ' ' << r << endl;
    }
    
    return 0;
}