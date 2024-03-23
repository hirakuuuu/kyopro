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
    const ll n = (1<<20);
    set<ll> s;
    rep(i, 0, 2*n) s.insert((ll)i);
    vector<ll> a(n, -1);
    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            ll x; cin >> x;
            ll m = x%n;
            auto itr = s.lower_bound(m);
            ll pos = (*itr)%n;
            a[pos] = x;
            s.erase(pos);
            s.erase(pos+n);
        }else{
            ll x; cin >> x;
            cout << a[x%n] << endl;
        }

    }

    return 0;
}