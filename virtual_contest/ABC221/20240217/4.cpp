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
    int n; cin >> n;
    vector<ll> a(n), b(n);
    vector<pair<ll, ll>> d(2*n);
    rep(i, 0, n){
        cin >> a[i] >> b[i];
        d[2*i] = {a[i], 1};
        d[2*i+1] = {a[i]+b[i], -1};
    }
    sort(d.begin(), d.end());
    vector<ll> cnt(n+1);
    ll tmp = 0, pre = 0;
    rep(i, 0, 2*n){
        auto [cur, j] = d[i];
        cnt[tmp] += cur-pre;
        tmp += j;
        pre = cur;
    }
    rep(i, 1, n+1){
        cout << cnt[i] << ' ';
    }
    cout << endl;
    return 0;
}