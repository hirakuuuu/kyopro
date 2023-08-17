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
// https://atcoder.jp/contests/arc133/tasks/arc133_c

int main(){
    ll h, w, k; cin >> h >> w >> k;
    vector<ll> a(h), b(w);
    rep(i, 0, h) cin >> a[i];
    rep(i, 0, w) cin >> b[i];

    ll sum_a = 0, sum_b = 0;
    rep(i, 0, h) sum_a += a[i];
    rep(i, 0, w) sum_b += b[i];
    
    if(sum_a%k != sum_b%k){
        cout << -1 << endl;
        return 0;
    }

    ll total_a = 0;
    rep(i, 0, h){
        ll tmp = (w*(k-1)/k)*k;
        if(tmp+a[i] > w*(k-1)) tmp -= k;
        total_a += tmp+a[i];
    }
    ll total_b = 0;
    rep(i, 0, w){
        ll tmp = (h*(k-1)/k)*k;
        if(tmp+b[i] > h*(k-1)) tmp -= k;
        total_b += tmp+b[i];
    }
    cout << min(total_a, total_b) << endl;
    
    return 0;
}