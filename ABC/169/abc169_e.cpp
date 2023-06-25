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
// https://atcoder.jp/contests/abc169/tasks/abc169_e

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int minm, maxm, ans;
    if(n%2 == 1){
        minm = a[n/2];
        maxm = b[n/2];
    }else{
        minm = a[n/2-1]+a[n/2];
        maxm = b[n/2-1]+b[n/2];
    }
    cout << maxm-minm+1 << endl;
    return 0;
}