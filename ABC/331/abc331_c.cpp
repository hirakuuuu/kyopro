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
// https://atcoder.jp/contests/abc331/tasks/abc331_c



int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> b = a;
    sort(b.begin(), b.end());
    vector<ll> acc(n+1);
    rrep(i, n-1, 0){
        acc[i] = acc[i+1]+b[i];
    }

    rep(i, 0, n){
        int pos = upper_bound(b.begin(), b.end(), a[i])-b.begin();
        cout << acc[pos] << ' ';
    }
    cout << endl;

    return 0;
}