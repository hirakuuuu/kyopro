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
// https://atcoder.jp/contests/abc334/tasks/abc334_d

int main(){
    int n, q; cin >> n >> q;
    vector<ll> r(n);
    rep(i, 0, n) cin >> r[i];
    sort(r.begin(), r.end());
    vector<ll> acc(n+1);
    rep(i, 1, n+1) acc[i] = acc[i-1]+r[i-1];
    while(q--){
        ll x; cin >> x;
        int cnt = upper_bound(acc.begin(), acc.end(), x)-acc.begin();
        cnt--;
        cout << cnt << endl;
    }
    
    return 0;
}