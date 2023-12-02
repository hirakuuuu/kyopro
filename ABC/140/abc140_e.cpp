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
// https://atcoder.jp/contests/abc140/tasks/abc140_e

int main(){
    int n; cin >> n;
    vector<int> p(n);
    rep(i, 0, n){
        cin >> p[i];
        p[i]--;
    }

    vector<ll> pos(n);
    rep(i, 0, n) pos[p[i]] = i+1;

    multiset<ll> s;
    s.insert(pos[n-1]);
    rep(i, 0, 2) s.insert(0);
    rep(i, 0, 2) s.insert(n+1);

    ll ans = 0;
    for(ll i = n-2; i >= 0; i--){
        // for(auto ss: s){
        //     cout << ss << ' ';
        // }
        // cout << endl;
        // ans += i*(区間の個数)
        ll q = pos[i];
        auto itr = s.lower_bound(q);
        ll r1 = *itr;
        itr++;
        ll r2 = *itr;
        rep(_, 0, 2) itr--;
        ll l1 = *itr;
        itr--;
        ll l2 = *itr;

        // l2 <= l1 <= q <= r1 <= r2;
        //cout << l2 << ' ' << l1 << ' ' << q << ' ' << r1 << ' '  << r2 << endl;

        ans += (i+1)*(r2-r1)*(q-l1);
        ans += (i+1)*(l1-l2)*(r1-q);
        //cout << ans << endl;
        s.insert(q);
    }

    cout << ans << endl;
    
    return 0;
}