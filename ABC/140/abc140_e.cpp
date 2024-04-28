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
    vector<int> p(n), rev(n);
    rep(i, 0, n){
        cin >> p[i];
        p[i]--;
        rev[p[i]] = i;
    }
    multiset<int> pos;
    pos.insert(-1);
    pos.insert(-1);
    pos.insert(rev[n-1]);
    pos.insert(n);
    pos.insert(n);
    ll ans = 0;
    rrep(i, n-2, 0){
        auto itr = pos.lower_bound(rev[i]);
        int l2 = *itr; itr++;
        int r2 = *itr; itr--;
        itr--;
        int r1 = *itr; itr--;
        int l1 = *itr; itr++;
        // (l1, r1], ... , i , ... , [l2, r2)
        ans += (ll)(r2-l2)*(rev[i]-r1)*(i+1);
        ans += (ll)(r1-l1)*(l2-rev[i])*(i+1);
        // cout << l1 << ' ' << r1 << ' ' << rev[i] << ' ' << l2 << ' ' << r2 << endl;
        pos.insert(rev[i]);
        // cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}