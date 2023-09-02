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
// https://atcoder.jp/contests/abc318/tasks/abc318_e

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i]--;
    }

    vector<ll> cnt(n), sum(n);
    ll ans = 0;
    rep(i, 0, n){
        ans += (cnt[a[i]]*i-sum[a[i]])-cnt[a[i]];
        ans -= (cnt[a[i]])*(cnt[a[i]]-1)/2;
        cnt[a[i]]++;
        sum[a[i]] += i;
    }

    cout << ans << endl;

    
    return 0;
}