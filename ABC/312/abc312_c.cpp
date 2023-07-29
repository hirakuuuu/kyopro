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
// https://atcoder.jp/contests/abc312/tasks/abc312_c

int main(){
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    rep(i, 0, n){
        cin >> a[i];
    }
    rep(i, 0, m){
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = b[m-1]+1;
    rep(i, 0, n){
        int cnt = b.end()-lower_bound(b.begin(), b.end(), a[i]);
        if(i+1 >= cnt){
            chmin(ans, a[i]);
        }
    }
    rep(i, 0, m){
        int cnt = upper_bound(a.begin(), a.end(), b[i]+1)-a.begin();
        if(cnt == 0) continue;

        if(cnt >= m-i-1) chmin(ans, b[i]+1);
    }

    cout << ans << endl;
    
    return 0;
}